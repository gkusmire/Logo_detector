//
// Created by grzegorz on 26.12.18.
//

#include "ObjectFeatures.h"

ObjectFeatures::ObjectFeatures(cv::Vec3b color_) {
    color = color_;
}

void ObjectFeatures::setCircus(double circus_) {
    circus = circus_;
}

void ObjectFeatures::setArea(double area_) {
    area = area_;
}

