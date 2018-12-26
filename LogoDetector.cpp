//
// Created by grzegorz on 24.12.18.
//

#include "LogoDetector.h"

LogoDetector::LogoDetector(std::string& pictureName) {
    this->pictureReader = new PictureReader();
    this->image = pictureReader->readPicture(pictureName);
    preprocessor = new Preprocessor();
}

LogoDetector::~LogoDetector() {
    delete pictureReader;
    delete preprocessor;
}

void LogoDetector::showLogos() {
    std::string a = "Znalezione znaki Pepsi";
    pictureReader->showPicture(image, a);
}

void LogoDetector::detectLogos() {
    doImagePreprocessing();
  //  extractFeatures();
//    analyzeFeatures();
}

void LogoDetector::doImagePreprocessing() {
    preprocessor->doPreprocessing(image);
}

//void LogoDetector::extractFeatures() {
//    FeaturesExtractor* extractor = new FeaturesExtractor();
//
//    ObjectsFeatures* objects = new ObjectsFeatures();
//
//    extractFeatures(Color::RED, extractor, objects, preprocessor->getRedColorVector());
//    extractFeatures(Color::BLUE, extractor, objects, preprocessor->getBlueColorVector());
//
//    delete extractor;
//}
//
//void LogoDetector::extractFeatures(Color color, FeaturesExtractor *extractor, ObjectsFeatures *objects,
//        std::vector<cv::Vec3b> colors) {
//
//    for(auto c: colors) {
////        objects->addObject(color, extractor->getCircuit(c,image), extractor->getObjectArea(c, image));
//    }
//}
