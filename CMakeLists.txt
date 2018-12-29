cmake_minimum_required(VERSION 2.8.4)
project(Logo_detector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package( OpenCV REQUIRED )
set(SOURCE_FILES main.cpp)
add_executable(Logo_detector main.cpp LogoDetector.cpp LogoDetector.h PictureReader.cpp PictureReader.h Preprocessor.cpp Preprocessor.h ColorAreasFinder.cpp ColorAreasFinder.h ObjectFeatures.cpp ObjectFeatures.h FeaturesExtractor.cpp FeaturesExtractor.h DetectedObjects.cpp DetectedObjects.h FiltrationMaker.cpp FiltrationMaker.h)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries( Logo_detector ${OpenCV_LIBS})