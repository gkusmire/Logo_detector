//
// Created by grzegorz on 19.01.19.
//

#ifndef LOGO_DETECTOR_RECTANGLESEXTRACTOR_H
#define LOGO_DETECTOR_RECTANGLESEXTRACTOR_H


#include <opencv2/core/mat.hpp>
#include "RectanglesList.h"

class RectanglesExtractor {

public:
    void extractRectangles(cv::Mat&, RectanglesList*);

private:
    cv::Vec3b backgroundColor = {0,0,100};
};


#endif //LOGO_DETECTOR_RECTANGLESEXTRACTOR_H
