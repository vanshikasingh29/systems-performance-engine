#include "allocator.h"

#include <stdlib.h>

static AllocationStats stats;


void *system_alloc(size_t size)
{
    void *ptr = malloc(size);

    if (ptr != NULL)
    {
        stats.allocations++;
        stats.bytes_allocated += size;
    }

    return ptr;
}


void system_free(void *ptr, size_t size)
{
    if (ptr == NULL)
    {
        return;
    }

    free(ptr);

    stats.frees++;
    stats.bytes_freed += size;
}


AllocationStats allocator_stats(void)
{
    return stats;
}


void allocator_reset(void)
{
    stats.allocations = 0;
    stats.frees = 0;
    stats.bytes_allocated = 0;
    stats.bytes_freed = 0;
}
