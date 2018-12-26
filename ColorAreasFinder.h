//
// Created by grzegorz on 25.12.18.
//

#ifndef LOGO_DETECTOR_COLORAREASFINDER_H
#define LOGO_DETECTOR_COLORAREASFINDER_H

#include <opencv2/core/mat.hpp>
#include<iostream>

enum Color {RED, WHITE, BLUE, ANOTHER};

class ColorAreasFinder {

public:
    ColorAreasFinder();
    void extractColorAreas(cv::Mat&);
    std::vector<cv::Vec3b> getRedColorVector();
    std::vector<cv::Vec3b> getWhiteColorVector();
    std::vector<cv::Vec3b> getBlueColorVector();

private:
    std::vector<cv::Vec3b> redColorVector;
    std::vector<cv::Vec3b> blueColorVector;
    std::vector<cv::Vec3b> whiteColorVector;
    Color getPixelColor(cv::Vec3b &);
    bool isRed(cv::Vec3b&);
    bool isBlue(cv::Vec3b&);
    bool isWhite(cv::Vec3b&);
    cv::Vec3b getColorVal();
    void findColorArea(Color, cv::Vec3b, int, int, bool**, cv::Mat_<cv::Vec3b>&);

    void addColorVal(Color, cv::Vec3b&);
    cv::Vec3b actualColor;
    cv::Vec3b darkColor;
};


#endif //LOGO_DETECTOR_COLORAREASFINDER_H
