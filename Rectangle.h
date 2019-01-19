//
// Created by grzegorz on 19.01.19.
//

#ifndef LOGO_DETECTOR_RECTANGLE_H
#define LOGO_DETECTOR_RECTANGLE_H


class Rectangle {

public:
    Rectangle(int, int, int, int);
    bool isPointInsideRectangle(int, int);

private:
    int minX, maxX, minY, maxY;
};


#endif //LOGO_DETECTOR_RECTANGE_H
