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
    double computeW3(double, double);
    double computeObjectCircuit(cv::Mat&, cv::Vec3b&);
    double computeObjectArea(cv::Mat&, cv::Vec3b&);
    double getM(const cv::Mat&, const cv::Vec3b&, int, int);
    double computeM7(cv::Mat&, cv::Vec3b&);
    double computeM3(cv::Mat&, cv::Vec3b&);
    void setObjectDimension(ObjectFeatures*, cv::Mat&);
};


#endif //LOGO_DETECTOR_FEATURESEXTRACTOR_H
