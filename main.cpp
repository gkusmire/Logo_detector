#include <iostream>
#include "LogoDetector.h"

int main() {
    std::string pictureName = "bbb.png";
    LogoDetector* detector;

//    std::cout << "Podaj proszę nazwę obrazu: ";
//    std::cin >> pictureName;

    detector = new LogoDetector(pictureName);
    detector->detectLogos();
    detector->showLogos();
    cv::waitKey(-1);

    delete detector;
    return 0;
}