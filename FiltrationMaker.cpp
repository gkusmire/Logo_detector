//
// Created by grzegorz on 29.12.18.
//

#include <iostream>
#include "FiltrationMaker.h"

void FiltrationMaker::doFiltration(cv::Mat &image, int (*filter)[5]) {

    cv::Mat_<cv::Vec3b> _I = image.clone();
    cv::Mat_<cv::Vec3b> filtered = image;
    cv::Vec3b pixelColor;
    int filterSum;

    if(image.cols<5 || image.rows<5)
        return;

    filterSum = getFilterElementsSum(filter);

    for(int i=2; i<image.cols-2; ++i)
        for(int j=2; j<image.rows-2; ++j) {
            pixelColor = getPixelColorAfterFiltering(_I, filter, i, j, filterSum);
            filtered(i,j) = pixelColor;
        }

    image = filtered;
}

int FiltrationMaker::getFilterElementsSum(int (*filter)[5]) {

    int sum = 0;

    for(int i=0; i<5; ++i)
        for(int j=0; j<5; ++j)
            sum += filter[i][j];

    return sum;
}

cv::Vec3b FiltrationMaker::getPixelColorAfterFiltering(cv::Mat_<cv::Vec3b> &image, int (*filter)[5],
        int x, int y, int filterSum) {

    cv::Vec3b pixelColor = {0,0,0};
    int rColor=0 , gColor=0, bColor=0;
    int indexX, indexY;

    for(int i=0; i<5; ++i)
        for(int j=0; j<5; ++j)
        {
            indexX = x-2+i;
            indexY = y-2+j;
            bColor += image(indexX, indexY)[0] * filter[i][j];
            gColor += image(indexX, indexY)[1] * filter[i][j];
            rColor += image(indexX, indexY)[2] * filter[i][j];
        }

    pixelColor[0] = dividePixelColorComponent(bColor, filterSum);
    pixelColor[1] = dividePixelColorComponent(gColor, filterSum);
    pixelColor[2] = dividePixelColorComponent(rColor, filterSum);

    return pixelColor;
}

uchar FiltrationMaker::dividePixelColorComponent(int color, int sum) {

    int value;

    if(sum == 0)
        sum=1;
    value = color/abs(sum);

    if(value > 255)
        value = 255;
    else if(value < 0)
        value = 0;

    return value;
}
