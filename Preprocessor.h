//
// Created by grzegorz on 24.12.18.
//

#ifndef LOGO_DETECTOR_PREPROCESSOR_H
#define LOGO_DETECTOR_PREPROCESSOR_H
#include<iostream>
#include <opencv2/core/mat.hpp>
#include"ColorAreasFinder.h"
#include "DetectedObjects.h"

class Preprocessor {

public:
    Preprocessor();
    void doPreprocessing(cv::Mat&, DetectedObjects*);

private:
    void extractColorAreas(cv::Mat&, DetectedObjects*);
    bool isRed(cv::Vec3b);
    bool isWhite(cv::Vec3b);
    bool isBlue(cv::Vec3b);

    Color getPixelColor(cv::Vec3b &vec);
};


#endif //LOGO_DETECTOR_PREPROCESSOR_H
