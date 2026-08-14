#include "cpu.h"

#include <stdio.h>
#include <unistd.h>


unsigned int cpu_count(void)
{
    long count =
        sysconf(_SC_NPROCESSORS_ONLN);

    if (count < 1)
    {
        return 1;
    }

    return (unsigned int)count;
}


void print_cpu_information(void)
{
    printf("\nCPU Information\n");
    printf("-------------------------\n");

    printf(
        "Logical processors: %u\n",
        cpu_count()
    );

#if defined(__x86_64__)
    printf("Architecture: x86-64\n");
#elif defined(__aarch64__)
    printf("Architecture: ARM64\n");
#else
    printf("Architecture: unknown\n");
#endif

    printf(
        "Compiler architecture: %zu-bit\n",
        sizeof(void *) * 8
    );
}