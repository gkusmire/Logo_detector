//
// Created by grzegorz on 25.12.18.
//

#ifndef LOGO_DETECTOR_COLORAREASFINDER_H
#define LOGO_DETECTOR_COLORAREASFINDER_H

#include <opencv2/core/mat.hpp>
#include<iostream>
#include "DetectedObjects.h"

enum Color {RED, WHITE, BLUE, ANOTHER};

class ColorAreasFinder {

public:
    ColorAreasFinder();
    void extractColorAreas(cv::Mat&, DetectedObjects*);

private:
    Color getPixelColor(cv::Vec3b &);
    bool isRed(cv::Vec3b&);
    bool isBlue(cv::Vec3b&);
    bool isWhite(cv::Vec3b&);
    cv::Vec3b getColorVal();
    void findColorArea(Color, cv::Vec3b, int, int, bool**, cv::Mat_<cv::Vec3b>&);

    void addColorVal(Color, cv::Vec3b, DetectedObjects*);
    cv::Vec3b actualColor;
    cv::Vec3b darkColor;
    cv::Vec3b whiteColor;
};


#endif //LOGO_DETECTOR_COLORAREASFINDER_H
