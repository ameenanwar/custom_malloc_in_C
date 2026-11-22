#include<stddef.h>
typedef struct Block
{
    size_t size;
    int is_free;
    struct Block *next;
    
    /* data */
} Block;

void my_allocator_init(void *memory, size_t size);
void *my_malloc(size_t size);



