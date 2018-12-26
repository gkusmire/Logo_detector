//
// Created by grzegorz on 24.12.18.
//

#ifndef LOGO_DETECTOR_PREPROCESSOR_H
#define LOGO_DETECTOR_PREPROCESSOR_H
#include<iostream>
#include <opencv2/core/mat.hpp>
#include"ColorAreasFinder.h"

class Preprocessor {

public:
    Preprocessor();
    void doPreprocessing(cv::Mat&);
    std::vector<cv::Vec3b> getRedColorVector();
    std::vector<cv::Vec3b> getWhiteColorVector();
    std::vector<cv::Vec3b> getBlueColorVector();

private:
    void extractColorAreas(cv::Mat&);
    bool isRed(cv::Vec3b);
    bool isWhite(cv::Vec3b);
    bool isBlue(cv::Vec3b);

    std::vector<cv::Vec3b> redColor;
    std::vector<cv::Vec3b> whiteColor;
    std::vector<cv::Vec3b> blueColor;

    Color getPixelColor(cv::Vec3b &vec);
};


#endif //LOGO_DETECTOR_PREPROCESSOR_H
