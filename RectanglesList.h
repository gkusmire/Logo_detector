//
// Created by grzegorz on 19.01.19.
//

#ifndef LOGO_DETECTOR_RECTANGLESLIST_H
#define LOGO_DETECTOR_RECTANGLESLIST_H


#include "ObjectFeatures.h"
#include <vector>
#include "Rectangle.h"

class RectanglesList {

public:
    void addLogoCoordinates(ObjectFeatures *redObject, ObjectFeatures *blueObject);
    bool isPointInsideLogoRectangle(int, int);

private:
    std::vector<Rectangle*> rectangles;
};


#endif //LOGO_DETECTOR_RECTANGLESLIST_H
