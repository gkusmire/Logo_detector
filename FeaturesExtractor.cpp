//
// Created by grzegorz on 26.12.18.
//

#include <opencv2/core/mat.hpp>
#include "FeaturesExtractor.h"

FeaturesExtractor::FeaturesExtractor() {}

void FeaturesExtractor::extractObjectsFeatures(cv::Mat &image, DetectedObjects *objects) {
    extractFeatures(image, objects->getRedColorObjects());
    extractFeatures(image, objects->getBlueColorObjects());
    extractFeatures(image, objects->getWhiteColorObjects());
}

void FeaturesExtractor::extractFeatures(cv::Mat &image, std::vector<ObjectFeatures *> &objects) {

    for(auto obj : objects) {
        obj->setArea(computeObjectArea(image, obj->getColor()));
        obj->setCircus(computeObjectCircuit(image, obj->getColor()));
        obj->setW3(computeW3(obj->getArea(), obj->getCircus()));
        obj->setM3(computeM3(image, obj->getColor()));
        obj->setM7(computeM7(image, obj->getColor()));
    }
}

double FeaturesExtractor::computeW3(double area, double circuit) {
    return circuit / (2 * sqrt( CV_PI * area )) - 1;
}

double FeaturesExtractor::computeObjectCircuit(cv::Mat &image, cv::Vec3b &color) {

    cv::Vec3b marker_color = {10,10,10};
    cv::Vec3b backgroundColor = {0,0,0};
    cv::Mat_<cv::Vec3b> _I = image;
    int x[] = {-1,-1,-1,0,0,1,1,1};
    int y[] = {1,0,-1,1,-1,1,0,-1};
    double counter = 0;

    for (int i = 0; i < _I.cols; ++i)
        for (int j = 0; j < _I.rows; ++j) {
            if(_I(i,j) == color)
                for(int m=0; m<8; ++m) {
                    if(_I(i+x[m],j+y[m]) == backgroundColor && _I(i,j) == color) {
                        _I(i + x[m], j + y[m]) = marker_color;
                        ++counter;
                    }
                }
        }
    return counter;
}

double FeaturesExtractor::computeObjectArea(cv::Mat &image, cv::Vec3b &color) {

    cv::Mat_<cv::Vec3b> _I = image;
    double counter = 0;
    for(int i=0; i<image.cols; ++i)
        for(int j=0; j<image.rows; ++j) {
            if(_I(i,j)==color)
                ++counter;
        }
    return counter;
}

double FeaturesExtractor::getM(const cv::Mat& I, const cv::Vec3b& color, int x, int y) {

    double n = 0;
    cv::Mat_<cv::Vec3b> _I = I;

    for (int i = 0; i < I.rows; ++i)
        for (int j = 0; j < I.cols; ++j)
            if (_I(i, j) == color) {
                n += pow(i, x) * pow(j, y);
            }

    return n;
}

double FeaturesExtractor::computeM7(cv::Mat &image, cv::Vec3b& color) {
    double M20, M02, M11;

    double m20 = getM(image,color,2,0);
    double m10 = getM(image,color,1,0);
    double m00 = getM(image,color,0,0);
    double m02 = getM(image,color,0,2);
    double m01 = getM(image,color,0,1);
    double m11 = getM(image,color,1,1);

    M02 = m02 - pow(m01,2)/m00;
    M20 = m20 - pow(m10,2)/m00;
    M11 = m11 - m10*m01/m00;

    return (M20*M02 - pow(M11,2))/pow(m00,4);
}

double FeaturesExtractor::computeM3(cv::Mat &image, cv::Vec3b& color) {
    double M30, M12, M21, M03;

    double m00 = getM(image,color,0,0);
    double m30 = getM(image,color,3,0);
    double m20 = getM(image,color,2,0);
    double m10 = getM(image,color,1,0);
    double m12 = getM(image,color,1,2);
    double m11 = getM(image,color,1,1);
    double m02 = getM(image,color,0,2);
    double m21 = getM(image,color,2,1);
    double m03 = getM(image,color,0,3);
    double m01 = getM(image,color,0,1);
    double i = m10/m00;
    double j = m01/m00;

    M30 = m30 - 3*m20*i + 2*m10*pow(i,2);
    M12 = m12 - 2*m11*j - m02*i + 2*m10*pow(j,2);
    M21 = m21 - 2*m11*i - m20*j + 2*m01*pow(i,2);
    M03 = m03 - 3*m02*j + 2*m01*pow(j,2);

    return pow(M30-3*M12,2) + pow(3*M21-M03,2)/pow(m00,5);
}

