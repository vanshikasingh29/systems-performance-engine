#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stddef.h>

typedef struct
{
    size_t allocations;
    size_t frees;
    size_t bytes_allocated;
    size_t bytes_freed;
} AllocationStats;

void *system_alloc(size_t size);

void system_free(void *ptr, size_t size);

AllocationStats allocator_stats(void);

void allocator_reset(void);

#endif