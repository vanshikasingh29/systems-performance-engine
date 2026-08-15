#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "allocator.h"
#include "bitops.h"
#include "cpu.h"
#include "benchmark.h"
#include "algorithms.h"


typedef struct
{
    const int *array;
    size_t size;
} BenchmarkData;


static long long sequential_adapter(
    void *data
)
{
    BenchmarkData *input =
        (BenchmarkData *)data;

    return sequential_sum(
        input->array,
        input->size
    );
}


static long long strided_adapter(
    void *data
)
{
    BenchmarkData *input =
        (BenchmarkData *)data;

    return strided_sum(
        input->array,
        input->size,
        16
    );
}


int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" Systems Performance Toolkit\n");
    printf("========================================\n");


    /*
    --------------------------------------------------------
    CPU
    --------------------------------------------------------
    */

    print_cpu_information();


    /*
    --------------------------------------------------------
    Bit operations
    --------------------------------------------------------
    */

    printf("\nBit Operations\n");
    printf("-------------------------\n");

    uint64_t value = 0;

    value = bit_set(value, 3);

    printf(
        "Set bit 3: %llu\n",
        (unsigned long long)value
    );

    printf(
        "Bit 3 set: %s\n",
        bit_test(value, 3)
            ? "yes"
            : "no"
    );

    printf(
        "Set bits: %u\n",
        bit_count(value)
    );


    /*
    --------------------------------------------------------
    Memory allocation
    --------------------------------------------------------
    */

    printf("\nMemory Allocation\n");
    printf("-------------------------\n");

    allocator_reset();

    size_t size = 1000000;

    int *array =
        system_alloc(
            size * sizeof(int)
        );

    if (array == NULL)
    {
        fprintf(
            stderr,
            "Allocation failed.\n"
        );

        return EXIT_FAILURE;
    }


    for (size_t i = 0; i < size; i++)
    {
        array[i] = 1;
    }


    AllocationStats stats =
        allocator_stats();

    printf(
        "Allocations: %zu\n",
        stats.allocations
    );

    printf(
        "Bytes allocated: %zu\n",
        stats.bytes_allocated
    );


    /*
    --------------------------------------------------------
    Benchmark
    --------------------------------------------------------
    */

    BenchmarkData data =
    {
        array,
        size
    };


    long long sequential_result;

    long long strided_result;


    double sequential_time =
        benchmark_run(
            sequential_adapter,
            &data,
            &sequential_result
        );


    double strided_time =
        benchmark_run(
            strided_adapter,
            &data,
            &strided_result
        );


    printf("\nPerformance\n");
    printf("-------------------------\n");

    printf(
        "Sequential sum: %lld\n",
        sequential_result
    );

    printf(
        "Sequential time: %.6f seconds\n",
        sequential_time
    );

    printf(
        "Strided sum: %lld\n",
        strided_result
    );

    printf(
        "Strided time: %.6f seconds\n",
        strided_time
    );


    /*
    --------------------------------------------------------
    Cleanup
    --------------------------------------------------------
    */

    system_free(
        array,
        size * sizeof(int)
    );


    stats =
        allocator_stats();


    printf(
        "\nAllocations: %zu\n",
        stats.allocations
    );

    printf(
        "Frees: %zu\n",
        stats.frees
    );


    printf(
        "\nSystems performance demonstration complete.\n"
    );


    return EXIT_SUCCESS;
}