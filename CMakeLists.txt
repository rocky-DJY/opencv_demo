cmake_minimum_required(VERSION 3.16)
set(CMAKE_BUILD_TYPE "Realese")
set(CMAKE_CXX_STANDARD 20)
project(opencv_demo)
# find opencv head file and lib file
set(CMAKE_PREFIX_PATH   /home/lab307/DJY/opencv3411/release)
find_package(OpenCV REQUIRED)
# find zed and cuda head file
set(INC_DIR /usr/local/zed/include)
set(LINK_DIR /usr/local/zed/lib)
set(zed_lib_list libsl_ai.so libsl_zed.so)
# include path
include_directories("/usr/local/cuda-10.2/include")
include_directories(${OpenCV_INCLUDE_DIRS} ${INC_DIR})
# lib path
link_directories(${LINK_DIR})

add_executable(opencv_demo main.cpp census.cpp census.h dispart_estimate.cpp dispart_estimate.h)
# link lib
target_link_libraries(opencv_demo ${OpenCV_LIBS} ${zed_lib_list})