cmake_minimum_required(VERSION 3.0)
project("Benchmark Fast-PCA")

set(CMAKE_CXX_STANDARD 17)

find_package(benchmark CONFIG REQUIRED)

include_directories("/usr/include/benchmark")
include_directories(headers)

include(${CMAKE_CURRENT_SOURCE_DIR}/../fast-PCA/CMakeLists.txt)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../fast-PCA/)

add_executable(mybenchmark mybenchmark.cpp)
target_link_libraries(mybenchmark benchmark::benchmark)
target_link_libraries(mybenchmark fast_pca)
