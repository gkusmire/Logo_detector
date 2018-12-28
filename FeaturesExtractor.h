//
// Created by grzegorz on 26.12.18.
//

#ifndef LOGO_DETECTOR_FEATURESEXTRACTOR_H
#define LOGO_DETECTOR_FEATURESEXTRACTOR_H

#include "DetectedObjects.h"

class FeaturesExtractor {

public:
    FeaturesExtractor();

    void extractObjectsFeatures(cv::Mat &image, DetectedObjects *objects);

private:
    void extractFeatures(cv::Mat&, std::vector<ObjectFeatures*>&);
};


#endif //LOGO_DETECTOR_FEATURESEXTRACTOR_H
