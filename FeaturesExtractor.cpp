//
// Created by grzegorz on 26.12.18.
//

#include "FeaturesExtractor.h"

FeaturesExtractor::FeaturesExtractor() {}

void FeaturesExtractor::extractObjectsFeatures(cv::Mat &image, DetectedObjects *objects) {
    extractFeatures(image, objects->getRedColorObjects());
    extractFeatures(image, objects->getBlueColorObjects());
    extractFeatures(image, objects->getWhiteColorObjects());
}

void FeaturesExtractor::extractFeatures(cv::Mat &, std::vector<ObjectFeatures *> &) {
    //TODO
}

