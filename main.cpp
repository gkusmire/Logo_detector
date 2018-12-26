#include <iostream>
#include "LogoDetector.h"

int main() {
    std::string pictureName = "elipsa1.dib";
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