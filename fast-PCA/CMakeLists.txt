cmake_minimum_required(VERSION 3.0)
project(ArrayFire-Example-Linear-Algebra
  VERSION 3.5.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
find_package(ArrayFire)


if(ArrayFire_CPU_FOUND)
  # SVD example
  add_executable(svd svd.cpp)
  target_link_libraries(svd ArrayFire::afcpu)
endif()

