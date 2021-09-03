cmake_minimum_required(VERSION 3.0)
project(fast-PCA
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Eigen3 REQUIRED)

add_library(fast_pca OBJECT ${CMAKE_CURRENT_SOURCE_DIR}/../fast-PCA/fast_pca.cpp)
add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/../fast-PCA/main.cpp)
target_link_libraries(fast_pca Eigen3::Eigen)
target_link_libraries(main fast_pca)

