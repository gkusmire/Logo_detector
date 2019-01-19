//
// Created by grzegorz on 16.01.19.
//

#ifndef LOGO_DETECTOR_OBJECTSANALYZER_H
#define LOGO_DETECTOR_OBJECTSANALYZER_H


#include "DetectedObjects.h"
#include "RectanglesList.h"

class ObjectsAnalyzer {

public:
    RectanglesList* analyzeObjects(DetectedObjects *);

private:

    double redObjectM7 = 0.00654014;
    double admissibleChangeForRedObjectM7 = 0.001;
    double blueObjectM7 = 0.0122364;
    double admissibleChangeForBlueObjectM7 = 0.01;
    double logoRectangleCoefficient = 1.2;
    double logoObjectsRectangleCoefficient = 1.2;

    void analyzeRedObjectsFeatures(DetectedObjects *objects);

    void analyzeBlueObjectsFeatures(DetectedObjects *objects);

    bool meetRequirements(ObjectFeatures *&object, double m7, double admissibleDeviation);

    void matchRedObjectsToBlueObjects(DetectedObjects *objects, RectanglesList *rectList);

    bool logoContainsObjects(ObjectFeatures *redObject, ObjectFeatures *blueObject);
};


#endif //LOGO_DETECTOR_OBJECTSANALYZER_H
