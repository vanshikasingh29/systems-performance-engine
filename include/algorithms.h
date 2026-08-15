#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stddef.h>

long long sequential_sum(
    const int *array,
    size_t size
);

long long strided_sum(
    const int *array,
    size_t size,
    size_t stride
);

#endif