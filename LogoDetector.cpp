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

void LogoDetector::showLogos(RectanglesList* rects) {

    std::string a = "Znalezione loga Pepsi";
    pictureReader->showPictureRects(a, rects);
}

void LogoDetector::detectLogos() {

    doImagePreprocessing();
    extractFeatures();
    std::cout<<"Czerwone: "<<std::endl;
    for(int i=0; i<objects->getRedColorObjects().size(); ++i) {
        std::cout << "Area: " << objects->getRedColorObjects()[i]->getArea() << " Circus: "
                  << objects->getRedColorObjects()[i]->getCircus() << " W3: "
                  << objects->getRedColorObjects()[i]->getW3() << " M3: " << objects->getRedColorObjects()[i]->getM3()
                  << " M7: " << objects->getRedColorObjects()[i]->getM7();
        std::cout << "  MinX: " << objects->getRedColorObjects()[i]->getMinX()<<" MaxX: "<<objects->getRedColorObjects()[i]->getMaxX()<<" MinY: "<<objects->getRedColorObjects()[i]->getMinY()<<" MaxY:"<<objects->getRedColorObjects()[i]->getMaxY()<<std::endl;
    }
    std::cout<<"Niebieskie: "<<std::endl;
    for(int i=0; i<objects->getBlueColorObjects().size(); ++i) {
        std::cout << "Area: " << objects->getBlueColorObjects()[i]->getArea() << " Circus: "
                  << objects->getBlueColorObjects()[i]->getCircus() << " W3: "
                  << objects->getBlueColorObjects()[i]->getW3() << " M3: " << objects->getBlueColorObjects()[i]->getM3()
                  << " M7: " << objects->getBlueColorObjects()[i]->getM7();
        std::cout << "  MinX: " << objects->getBlueColorObjects()[i]->getMinX()<<" MaxX: "<<objects->getBlueColorObjects()[i]->getMaxX()<<" MinY: "<<objects->getBlueColorObjects()[i]->getMinY()<<" MaxY:"<<objects->getBlueColorObjects()[i]->getMaxY()<<std::endl;

    }

    RectanglesList* rects = analyzeFeatures();
    showOriginalPicture();
    showLogos(rects);

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

RectanglesList* LogoDetector::analyzeFeatures() {

    RectanglesList* rects;
    ObjectsAnalyzer* analyzer = new ObjectsAnalyzer();
    rects = analyzer->analyzeObjects(this->objects);
    delete analyzer;

    return rects;
}

void LogoDetector::showOriginalPicture() {

    std::string a = "Oryginalny obraz";
    pictureReader->showOriginalPicture(a);
}
