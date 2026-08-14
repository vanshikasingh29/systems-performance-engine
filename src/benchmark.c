#include "benchmark.h"

#include <time.h>


double benchmark_run(
    BenchmarkFunction function,
    void *data,
    long long *result
)
{
    clock_t start = clock();

    *result = function(data);

    clock_t end = clock();

    return
        (double)(end - start)
        / (double)CLOCKS_PER_SEC;
}