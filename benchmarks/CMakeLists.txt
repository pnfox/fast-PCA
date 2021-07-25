cmake_minimum_required(VERSION 3.0)
project("Benchmark Fast-PCA")

set(CMAKE_CXX_STANDARD 17)
find_package(benchmark REQUIRED)

include_directories("/usr/include/benchmark")
include_directories(headers)

find_library(benchmark_LIBRARY NAMES "benchmark"
  PATHS ${benchmark_ROOT_DIR}
  PATH_SUFFIXES lib lib64
  NO_DEFAULT_PATH)
find_library(benchmark_LIBRARY NAMES "benchmark")


add_executable(mybenchmark mybenchmark.cpp)
target_link_libraries(mybenchmark ${benchmark_LIBRARY})
