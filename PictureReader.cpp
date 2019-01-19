//
// Created by grzegorz on 24.12.18.
//

#include "PictureReader.h"

PictureReader::PictureReader() {}

cv::Mat PictureReader::readPicture(std::string &pictureName) {

    this->pictureName = pictureName;
    cv::Mat image = cv::imread(pictureName);
    return image;
}

void PictureReader::showOriginalPicture(std::string title) {

    cv::Mat image = cv::imread(pictureName);
    cv::imshow(title, image);
}

void PictureReader::showPictureRects(std::string title, RectanglesList *rects) {

    cv::Mat image = cv::imread(pictureName);
    RectanglesExtractor* extractor = new RectanglesExtractor();
    extractor->extractRectangles(image, rects);

    delete extractor;
    cv::imshow(title, image);
}
