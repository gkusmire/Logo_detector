//
// Created by grzegorz on 24.12.18.
//

#ifndef LOGO_DETECTOR_PICTUREREADER_H
#define LOGO_DETECTOR_PICTUREREADER_H
#include<iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "RectanglesList.h"
#include "RectanglesExtractor.h"

class PictureReader {

public:
    PictureReader();
    cv::Mat readPicture(std::string&);

    void showOriginalPicture(std::string);

    void showPictureRects(std::string, RectanglesList*);

private:
    std::string pictureName;
};


#endif //LOGO_DETECTOR_PICTUREREADER_H
