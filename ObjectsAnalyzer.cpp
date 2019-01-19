//
// Created by grzegorz on 16.01.19.
//

#include "ObjectsAnalyzer.h"
#include <algorithm>

RectanglesList* ObjectsAnalyzer::analyzeObjects(DetectedObjects *objects) {

    RectanglesList* rectangleList = new RectanglesList();

    analyzeRedObjectsFeatures(objects);
    analyzeBlueObjectsFeatures(objects);

    matchRedObjectsToBlueObjects(objects, rectangleList);

    return rectangleList;
}

void ObjectsAnalyzer::analyzeRedObjectsFeatures(DetectedObjects *objects) {

    auto list = objects->getRedColorObjects();

    for(auto c=list.begin(); c!=list.end();) {

        if(!meetRequirements(*c, redObjectM7, admissibleChangeForRedObjectM7)) {

            delete (*c);
            list.erase(c);
        } else {
            ++c;
        }
    }
}

void ObjectsAnalyzer::analyzeBlueObjectsFeatures(DetectedObjects *objects) {

    auto list = objects->getBlueColorObjects();

    for(auto c=list.begin(); c!=list.end();) {

        if(!meetRequirements(*c, blueObjectM7, admissibleChangeForBlueObjectM7)) {

            delete (*c);
            list.erase(c);
        } else {
            ++c;
        }
    }
}

bool ObjectsAnalyzer::meetRequirements(ObjectFeatures *&object, double m7, double admissibleDeviation) {

    double objectM7 = object->getM7();

    if(objectM7<m7-admissibleDeviation || objectM7 > m7+admissibleDeviation)
        return false;
    return true;
}

void ObjectsAnalyzer::matchRedObjectsToBlueObjects(DetectedObjects *objects, RectanglesList *rectList) {

    auto redObjectsList = objects->getRedColorObjects();
    auto blueObjectsList = objects->getBlueColorObjects();

    for(auto redObject : redObjectsList) {

        for(auto blueObject : blueObjectsList) {

            if(logoContainsObjects(redObject, blueObject)) {
                rectList->addLogoCoordinates(redObject, blueObject);
            }
        }
    }
}

bool ObjectsAnalyzer::logoContainsObjects(ObjectFeatures *redObject, ObjectFeatures *blueObject) {

    auto logoMinX = std::min(redObject->getMinX(), blueObject->getMinX());
    auto logoMinY = std::min(redObject->getMinY(), blueObject->getMinY());
    auto logoMaxY = std::min(redObject->getMaxY(), blueObject->getMaxY());
    auto logoMaxX = std::min(redObject->getMaxX(), blueObject->getMaxX());

    auto logoXLength = logoMaxX - logoMinX;
    auto logoYLength = logoMaxY - logoMinY;

    if(std::max(logoXLength, logoYLength)/std::min(logoXLength, logoYLength) > 1.2)
        return false;

//TODO comparation with objects (redObject and blueObject) size
    return true;
}
