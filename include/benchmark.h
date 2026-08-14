#ifndef BENCHMARK_H
#define BENCHMARK_H

typedef long long (*BenchmarkFunction)(void *data);

double benchmark_run(
    BenchmarkFunction function,
    void *data,
    long long *result
);

#endif