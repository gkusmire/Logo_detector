//
// Created by grzegorz on 29.12.18.
//

#ifndef LOGO_DETECTOR_FILTRATIONMAKER_H
#define LOGO_DETECTOR_FILTRATIONMAKER_H


#include <opencv2/core/mat.hpp>

class FiltrationMaker {

public:
    void doFiltration(cv::Mat &, int (*)[5]);

private:
    int getFilterElementsSum(int (*)[5]);
    cv::Vec3b getPixelColorAfterFiltering(cv::Mat_<cv::Vec3b>&, int (*)[5], int, int, int);

    uchar dividePixelColorComponent(int color, int sum);
};


#endif //LOGO_DETECTOR_FILTRATIONMAKER_H
