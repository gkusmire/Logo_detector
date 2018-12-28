//
// Created by grzegorz on 24.12.18.
//

#include "LogoDetector.h"

LogoDetector::LogoDetector(std::string& pictureName) {
    this->pictureReader = new PictureReader();
    this->image = pictureReader->readPicture(pictureName);
    objects = new DetectedObjects();
}

LogoDetector::~LogoDetector() {
    delete pictureReader;
    delete objects;
}

void LogoDetector::showLogos() {
    std::string a = "Znalezione znaki Pepsi";
    pictureReader->showPicture(image, a);
}

void LogoDetector::detectLogos() {
    doImagePreprocessing();
    extractFeatures();
//    analyzeFeatures();
}

void LogoDetector::doImagePreprocessing() {
    Preprocessor* preprocessor = new Preprocessor();

    preprocessor->doPreprocessing(image, objects);

    delete preprocessor;
}

void LogoDetector::extractFeatures() {
    FeaturesExtractor* featuresExtractor = new FeaturesExtractor();
    featuresExtractor->extractObjectsFeatures(image, objects);
    delete featuresExtractor;
}
