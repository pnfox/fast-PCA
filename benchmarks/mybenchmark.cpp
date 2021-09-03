#ifdef __APPLE__
    #include <benchmark/benchmark.h>
#elif
    #include <benchmark.h>
#endif
#include <chrono>
#include "fast_pca.h"

static void BM_read_csv(benchmark::State& state) {
  for (auto _ : state)
    read_csv("../data/data.csv");
}
// Register the function as a benchmark
BENCHMARK(BM_read_csv);

static void BM_fast_pca(benchmark::State& state) {
  Eigen::MatrixXf data = read_csv("../data/data.csv");

  for (auto _ : state){
    auto start = std::chrono::high_resolution_clock::now();
    fast_PCA(data);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_seconds =
          std::chrono::duration_cast<std::chrono::duration<double>>(
            end - start);

    state.SetIterationTime(elapsed_seconds.count());
  }
}
BENCHMARK(BM_fast_pca)->UseManualTime();


BENCHMARK_MAIN();
