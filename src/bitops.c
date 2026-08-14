#include "bitops.h"


uint64_t bit_set(
    uint64_t value,
    unsigned int position
)
{
    return value | (UINT64_C(1) << position);
}


uint64_t bit_clear(
    uint64_t value,
    unsigned int position
)
{
    return value &
        ~(UINT64_C(1) << position);
}


uint64_t bit_toggle(
    uint64_t value,
    unsigned int position
)
{
    return value ^
        (UINT64_C(1) << position);
}


int bit_test(
    uint64_t value,
    unsigned int position
)
{
    return
        (value &
        (UINT64_C(1) << position)) != 0;
}


unsigned int bit_count(
    uint64_t value
)
{
    unsigned int count = 0;

    while (value != 0)
    {
        value &= value - 1;
        count++;
    }

    return count;
}