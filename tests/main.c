#include "allocator.h"
#include <stdio.h>

#define POOL_SIZE (1024 * 1024)

_Alignas(max_align_t)
static unsigned char memory_pool[POOL_SIZE];

int main(void)
{
    my_allocator_init(memory_pool, POOL_SIZE);

    printf("Allocator initialized.\n");

    return 0;
}