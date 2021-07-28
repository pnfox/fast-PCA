cmake_minimum_required(VERSION 3.0)
project(ArrayFire-Example-Linear-Algebra
  VERSION 3.5.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
find_package(ArrayFire)


if(ArrayFire_CPU_FOUND)
  # SVD example
  add_library(fast_pca OBJECT fast_pca.cpp)
  add_executable(svd svd.cpp)
  target_link_libraries(fast_pca ArrayFire::afcpu)
  target_link_libraries(svd fast_pca)
endif()

