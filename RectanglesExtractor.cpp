//
// Created by grzegorz on 19.01.19.
//

#include "RectanglesExtractor.h"

void RectanglesExtractor::extractRectangles(cv::Mat& image, RectanglesList *rects) {

    cv::Mat_<cv::Vec3b> _I = image;

    for(int i=0; i<image.rows; ++i)
        for(int j=0; j<image.cols; ++j) {

            if(!rects->isPointInsideLogoRectangle(i, j)) {
                _I(i,j) = backgroundColor;
            }
        }

    image = _I;
}
