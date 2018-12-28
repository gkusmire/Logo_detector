//
// Created by grzegorz on 24.12.18.
//

#ifndef LOGO_DETECTOR_LOGODETECTOR_H
#define LOGO_DETECTOR_LOGODETECTOR_H
#include <iostream>
#include "PictureReader.h"
#include "Preprocessor.h"
#include "FeaturesExtractor.h"
#include "ObjectFeatures.h"
#include "DetectedObjects.h"


class LogoDetector {

public:
    LogoDetector(std::string&);
    ~LogoDetector();
    void detectLogos();
    void showLogos();

private:
    void doImagePreprocessing();
    void extractFeatures();
    void extractFeatures(Color, FeaturesExtractor*, ObjectFeatures*, std::vector<cv::Vec3b>);

    PictureReader* pictureReader;
    cv::Mat image;
    DetectedObjects* objects;

};


#endif //LOGO_DETECTOR_LOGODETECTOR_H
