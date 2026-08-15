#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "allocator.h"
#include "bitops.h"
#include "algorithms.h"


static int passed = 0;
static int failed = 0;


static void assert_test(
    int condition,
    const char *name
)
{
    if (condition)
    {
        printf(
            "[PASS] %s\n",
            name
        );

        passed++;
    }
    else
    {
        printf(
            "[FAIL] %s\n",
            name
        );

        failed++;
    }
}


static void test_allocator(void)
{
    allocator_reset();

    int *value =
        system_alloc(sizeof(int));

    int valid =
        value != NULL;

    if (value != NULL)
    {
        *value = 42;

        valid =
            valid &&
            *value == 42;
    }

    assert_test(
        valid,
        "Heap allocation"
    );

    system_free(
        value,
        sizeof(int)
    );


    AllocationStats stats =
        allocator_stats();

    assert_test(
        stats.allocations == 1,
        "Allocation tracking"
    );

    assert_test(
        stats.frees == 1,
        "Deallocation tracking"
    );
}


static void test_bit_operations(void)
{
    uint64_t value = 0;

    value =
        bit_set(value, 5);

    assert_test(
        bit_test(value, 5),
        "Bit set and test"
    );


    value =
        bit_clear(value, 5);

    assert_test(
        !bit_test(value, 5),
        "Bit clear"
    );


    value =
        bit_toggle(value, 2);

    assert_test(
        bit_test(value, 2),
        "Bit toggle"
    );


    assert_test(
        bit_count(value) == 1,
        "Population count"
    );
}


static void test_algorithms(void)
{
    int values[] =
    {
        1, 2, 3, 4, 5
    };


    long long result =
        sequential_sum(
            values,
            5
        );


    assert_test(
        result == 15,
        "Sequential sum"
    );


    result =
        strided_sum(
            values,
            5,
            2
        );


    assert_test(
        result == 9,
        "Strided sum"
    );
}


int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" Systems Performance Test Suite\n");
    printf("========================================\n\n");


    test_allocator();

    test_bit_operations();

    test_algorithms();


    printf("\nResults\n");
    printf("-------------------------\n");

    printf(
        "Passed: %d\n",
        passed
    );

    printf(
        "Failed: %d\n",
        failed
    );


    if (failed == 0)
    {
        printf(
            "\nAll systems tests passed.\n"
        );

        return EXIT_SUCCESS;
    }


    printf(
        "\nSome systems tests failed.\n"
    );

    return EXIT_FAILURE;
}