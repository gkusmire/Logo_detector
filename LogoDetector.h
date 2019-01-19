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
#include "ObjectsAnalyzer.h"

class LogoDetector {

public:
    LogoDetector(std::string&);
    ~LogoDetector();
    void detectLogos();

private:
    void showLogos(RectanglesList* );
    void showOriginalPicture();
    void doImagePreprocessing();
    void extractFeatures();
    RectanglesList* analyzeFeatures();

    PictureReader* pictureReader;
    cv::Mat image;
    DetectedObjects* objects;

};


#endif //LOGO_DETECTOR_LOGODETECTOR_H
