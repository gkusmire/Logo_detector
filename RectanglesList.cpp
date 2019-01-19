//
// Created by grzegorz on 19.01.19.
//

#include "RectanglesList.h"

void RectanglesList::addLogoCoordinates(ObjectFeatures *redObject, ObjectFeatures *blueObject) {

    Rectangle* rect;
    auto minX = std::min(redObject->getMinX(), blueObject->getMinX());
    auto minY = std::min(redObject->getMinY(), blueObject->getMinY());
    auto maxY = std::max(redObject->getMaxY(), blueObject->getMaxY());
    auto maxX = std::max(redObject->getMaxX(), blueObject->getMaxX());

    rect = new Rectangle(minX, maxX, minY, maxY);

    rectangles.push_back(rect);
}

bool RectanglesList::isPointInsideLogoRectangle(int x, int y) {

    for(auto c : rectangles) {

        if(c->isPointInsideRectangle(x, y))
            return true;
    }

    return false;
}
