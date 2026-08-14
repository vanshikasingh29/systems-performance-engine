#ifndef BITOPS_H
#define BITOPS_H

#include <stdint.h>

uint64_t bit_set(
    uint64_t value,
    unsigned int position
);

uint64_t bit_clear(
    uint64_t value,
    unsigned int position
);

uint64_t bit_toggle(
    uint64_t value,
    unsigned int position
);

int bit_test(
    uint64_t value,
    unsigned int position
);

unsigned int bit_count(
    uint64_t value
);

#endif