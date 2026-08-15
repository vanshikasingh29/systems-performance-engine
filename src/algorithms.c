#include "algorithms.h"


long long sequential_sum(
    const int *array,
    size_t size
)
{
    long long sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}


long long strided_sum(
    const int *array,
    size_t size,
    size_t stride
)
{
    long long sum = 0;

    if (stride == 0)
    {
        return 0;
    }

    for (
        size_t i = 0;
        i < size;
        i += stride
    )
    {
        sum += array[i];
    }

    return sum;
}