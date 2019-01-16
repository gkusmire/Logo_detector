//
// Created by grzegorz on 28.12.18.
//

#include "DetectedObjects.h"

DetectedObjects::DetectedObjects() {}

DetectedObjects::~DetectedObjects() {
    for(auto x : redColorObjects)
        delete x;

    for(auto x : blueColorObjects)
        delete x;

}