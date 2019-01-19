//
// Created by grzegorz on 19.01.19.
//

#include "Rectangle.h"

Rectangle::Rectangle(int minX, int maxX, int minY, int maxY) {

    this->minX = minX;
    this->minY = minY;
    this->maxY = maxY;
    this->maxX = maxX;
}

bool Rectangle::isPointInsideRectangle(int x, int y) {

    if(x<=maxX && x>=minX && y<=maxY && y>= minY)
        return true;

    return false;
}
