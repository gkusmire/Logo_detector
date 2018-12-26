//
// Created by grzegorz on 25.12.18.
//

#include <opencv/cv.hpp>
#include "ColorAreasFinder.h"

ColorAreasFinder::ColorAreasFinder() {
    actualColor = {0,0,0};
    darkColor = {0,0,0};
}

void ColorAreasFinder::extractColorAreas(cv::Mat &image) {
    cv::Mat_<cv::Vec3b> _I = image;
    Color color;
    cv::Vec3b colorVal;
    bool** flagTable = new bool* [image.cols];
    for(int i=0; i<image.cols; ++i) {
        flagTable[i] = new bool[image.rows] {false};
    }

    for(int i=0; i<image.cols; ++i)
        for(int j=0; j<image.rows; ++j) {
            if(flagTable[i][j] == false) {
                color = getPixelColor(_I(i,j));
                if(color == Color::ANOTHER) {
                    colorVal = darkColor;
                } else {
                    colorVal = getColorVal();
                    addColorVal(color, colorVal);
                }
                findColorArea(color, colorVal, i, j, flagTable, _I);
            }
        }
    for(int i=0; i<image.cols;++i)
        delete[] flagTable[i];
    delete[] flagTable;
    image = _I;
}

std::vector<cv::Vec3b> ColorAreasFinder::getRedColorVector() {
    return redColorVector;
}

std::vector<cv::Vec3b> ColorAreasFinder::getWhiteColorVector() {
    return whiteColorVector;
}

std::vector<cv::Vec3b> ColorAreasFinder::getBlueColorVector() {
    return blueColorVector;
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
    if(i<0 || j<0 || i>=image.cols || j>=image.rows)
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
    //TODO
    return false;
}

bool ColorAreasFinder::isBlue(cv::Vec3b &pixel) {
    //TODO
    return false;
}

bool ColorAreasFinder::isWhite(cv::Vec3b &pixel) {
    //TODO
    if(pixel[0]<150 && pixel[1]<150 && pixel[2]<150)
        return true;
    return false;
}

cv::Vec3b ColorAreasFinder::getColorVal() {
    if(actualColor[0] == 254)
        actualColor[1] = 1;
    actualColor[0] += 1;
    return actualColor;
}

void ColorAreasFinder::addColorVal(Color color, cv::Vec3b& colorVal) {
    switch(color) {
        case Color::RED:
            redColorVector.push_back(colorVal);
            break;
        case Color::WHITE:
            whiteColorVector.push_back(colorVal);
            break;
        case Color::BLUE:
            blueColorVector.push_back(colorVal);
            break;
        default:
            return;
    }
}
