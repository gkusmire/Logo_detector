//
// Created by grzegorz on 28.12.18.
//

#ifndef LOGO_DETECTOR_DETECTEDOBJECTS_H
#define LOGO_DETECTOR_DETECTEDOBJECTS_H

#include <vector>
#include "ObjectFeatures.h"

class DetectedObjects {

public:
    DetectedObjects();
    ~DetectedObjects();
    void addRedObject(ObjectFeatures* obj) { redColorObjects.push_back(obj); }
    void addBlueObject(ObjectFeatures* obj) { blueColorObjects.push_back(obj); }
    std::vector<ObjectFeatures*>&  getRedColorObjects() { return redColorObjects; }
    std::vector<ObjectFeatures*>&  getBlueColorObjects() { return blueColorObjects; }

private:
    std::vector<ObjectFeatures*> redColorObjects;
    std::vector<ObjectFeatures*> blueColorObjects;
};


#endif //LOGO_DETECTOR_DETECTEDOBJECTS_H
