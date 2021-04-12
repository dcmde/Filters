cmake_minimum_required(VERSION 3.1)
project(filters)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(exp_smoothing src/exp_smoothing.cpp)
add_executable(double_exp_smoothing src/double_exp_smoothing.cpp)