//
// Created by grzegorz on 24.12.18.
//

#include "Preprocessor.h"

Preprocessor::Preprocessor() {
}

void Preprocessor::doPreprocessing(cv::Mat &image) {
    extractColorAreas(image);
}

void Preprocessor::extractColorAreas(cv::Mat &image) {
    ColorAreasFinder* finder = new ColorAreasFinder();
    finder->extractColorAreas(image);
    redColor = finder->getRedColorVector();
    blueColor = finder->getBlueColorVector();
    whiteColor = finder->getWhiteColorVector();
    delete finder;
}

std::vector<cv::Vec3b> Preprocessor::getRedColorVector() {
    return redColor;
}

std::vector<cv::Vec3b> Preprocessor::getWhiteColorVector() {
    return whiteColor;
}

std::vector<cv::Vec3b> Preprocessor::getBlueColorVector() {
    return blueColor;
}