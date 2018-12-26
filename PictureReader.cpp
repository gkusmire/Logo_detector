//
// Created by grzegorz on 24.12.18.
//

#include "PictureReader.h"

PictureReader::PictureReader() {}

void PictureReader::showPicture(cv::Mat &image, std::string &name) {
    cv::imshow(name, image);
}

cv::Mat PictureReader::readPicture(std::string &pictureName) {
    cv::Mat image = cv::imread(pictureName);
    return image;
}
