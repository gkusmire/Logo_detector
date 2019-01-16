//
// Created by grzegorz on 25.12.18.
//

#include <opencv/cv.hpp>
#include "ColorAreasFinder.h"

ColorAreasFinder::ColorAreasFinder() {
    actualColor = {0,0,0};
    darkColor = {0,255,0};
    whiteColor = {255,255,255};
}

void ColorAreasFinder::extractColorAreas(cv::Mat &image, DetectedObjects* objects) {
    cv::Mat_<cv::Vec3b> _I = image;
    Color color;
    cv::Vec3b colorVal;
    bool** flagTable = new bool* [image.rows];
    for(int i=0; i<image.rows; ++i) {
        flagTable[i] = new bool[image.cols] {false};
    }

    for(int i=0; i<image.rows; ++i)
        for(int j=0; j<image.cols; ++j) {
            if(flagTable[i][j] == false) {
                color = getPixelColor(_I(i,j));
                if(color == Color::ANOTHER) {
                    _I(i,j) = darkColor;
                    flagTable[i][j] = true;
                }
                if(color == Color::WHITE) {
                    _I(i,j) = whiteColor;
                    flagTable[i][j] = true;
                }
                if(color == Color::BLUE || color == Color::RED) {
                    colorVal = getColorVal();
                    addColorVal(color, colorVal, objects);
                    findColorArea(color, colorVal, i, j, flagTable, _I);
                }
            }
        }

    for(int i=0; i<image.rows;++i)
        delete[] flagTable[i];
    delete[] flagTable;
    image = _I;
}

Color ColorAreasFinder::getPixelColor(cv::Vec3b &pixel) {
    if(isRed(pixel))
        return Color::RED;
    if(isBlue(pixel))
        return Color::BLUE;
    if(isWhite(pixel))
        return Color::WHITE;
    return Color::ANOTHER;
}

void ColorAreasFinder::findColorArea(Color color, cv::Vec3b colorVal, int i, int j, bool** flagTable, cv::Mat_<cv::Vec3b>& image) {
    if(i<0 || j<0 || i>=image.rows || j>=image.cols)
        return;
    if(flagTable[i][j] == true)
        return;
    Color _color = getPixelColor(image(i,j));

    if(_color == Color::ANOTHER) {
        flagTable[i][j] = true;
        image(i,j) = darkColor;
    } else if(_color == color) {
        flagTable[i][j] = true;
        image(i,j) = colorVal;
        findColorArea(color, colorVal, i, j-1, flagTable, image);
        findColorArea(color, colorVal, i, j+1, flagTable, image);
        findColorArea(color, colorVal, i-1, j, flagTable, image);
        findColorArea(color, colorVal, i+1, j, flagTable, image);
        findColorArea(color, colorVal, i-1, j-1, flagTable, image);
        findColorArea(color, colorVal, i+1, j+1, flagTable, image);
        findColorArea(color, colorVal, i+1, j-1, flagTable, image);
        findColorArea(color, colorVal, i-1, j+1, flagTable, image);
    }
}

bool ColorAreasFinder::isRed(cv::Vec3b &pixel) {

    if(pixel[0]<100 && pixel[1]<110 && pixel[2]>150) {
        return true;
    }
    return false;
}

bool ColorAreasFinder::isBlue(cv::Vec3b &pixel) {
    if(pixel[0]>100 && pixel[1]<180 && pixel[2]<80) {
//        std::cout<<int(pixel[0])<<" "<<int(pixel[1])<<" "<<int(pixel[2])<<std::endl;
        return true;
    }
    return false;
}

bool ColorAreasFinder::isWhite(cv::Vec3b &pixel) {
    if(pixel[0]>200 && pixel[1]>200 && pixel[2]>200)
        return true;
    return false;
}

cv::Vec3b ColorAreasFinder::getColorVal() {
    if(actualColor[0] == 255)
        actualColor[1] += 1;
    actualColor[0] += 1;
    return actualColor;
}

void ColorAreasFinder::addColorVal(Color color, cv::Vec3b colorVal, DetectedObjects* objects) {

    switch(color) {
        case Color::RED:
            objects->addRedObject(new ObjectFeatures(colorVal));
            break;
        case Color::BLUE:
            objects->addBlueObject(new ObjectFeatures(colorVal));
            break;
        default:
            return;
    }
}
