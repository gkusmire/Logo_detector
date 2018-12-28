//
// Created by grzegorz on 26.12.18.
//

#ifndef LOGO_DETECTOR_OBJECTSFEATURES_H
#define LOGO_DETECTOR_OBJECTSFEATURES_H


#include <opencv2/core/matx.hpp>

class ObjectFeatures {

public:
    ObjectFeatures(cv::Vec3b);
    void setCircus(double);
    void setArea(double);
    void setM3(double val) { M3 = val; }
    void setM7(double val) { M7 = val; }
    void setW3(double val) { W3 = val; }

    cv::Vec3b& getColor() { return color; }
    double getCircus() { return circus; }
    double getArea() { return area; }
    double getW3() { return W3; }
    double getM3() { return M3; }
    double getM7() { return M7; }

private:
    double circus = 0;
    double area = 0;
    cv::Vec3b color = {0,0,0};
    double W3, M3, M7;
};


#endif //LOGO_DETECTOR_OBJECTSFEATURES_H
