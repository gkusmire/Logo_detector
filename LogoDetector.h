//
// Created by grzegorz on 24.12.18.
//

#ifndef LOGO_DETECTOR_LOGODETECTOR_H
#define LOGO_DETECTOR_LOGODETECTOR_H
#include <iostream>
#include "PictureReader.h"
#include "Preprocessor.h"
#include "FeaturesExtractor.h"
#include "ObjectsFeatures.h"


class LogoDetector {

public:
    LogoDetector(std::string&);
    ~LogoDetector();
    void detectLogos();
    void showLogos();

private:
    void doImagePreprocessing();
    void extractFeatures();
    void extractFeatures(Color, FeaturesExtractor*, ObjectsFeatures*, std::vector<cv::Vec3b>);

    PictureReader* pictureReader;
    cv::Mat image;
    Preprocessor* preprocessor;
};


#endif //LOGO_DETECTOR_LOGODETECTOR_H
