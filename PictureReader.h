//
// Created by grzegorz on 24.12.18.
//

#ifndef LOGO_DETECTOR_PICTUREREADER_H
#define LOGO_DETECTOR_PICTUREREADER_H
#include<iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

class PictureReader {

public:
    PictureReader();
    void showPicture(cv::Mat &image, std::string &name);
    cv::Mat readPicture(std::string&);
};


#endif //LOGO_DETECTOR_PICTUREREADER_H
