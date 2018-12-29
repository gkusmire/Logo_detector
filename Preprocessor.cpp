//
// Created by grzegorz on 24.12.18.
//

#include "Preprocessor.h"

Preprocessor::Preprocessor() {
}

void Preprocessor::doPreprocessing(cv::Mat &image, DetectedObjects* objects) {
    doFiltering(image);
    extractColorAreas(image, objects);
}

void Preprocessor::extractColorAreas(cv::Mat &image, DetectedObjects* objects) {
    ColorAreasFinder* finder = new ColorAreasFinder();
    finder->extractColorAreas(image, objects);
    delete finder;
}

void Preprocessor::doFiltering(cv::Mat& image) {

    FiltrationMaker* fMaker = new FiltrationMaker();
    fMaker->doFiltration(image, highPassFilter);
    delete fMaker;
}

