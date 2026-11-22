#include "allocator.h"

static Block *freeList = NULL;

void my_allocator_init(void *memory, size_t size)
{
    if(memory != NULL)
    {
    
    if(size <= sizeof(Block))
    {
        printf("Insuffienet memory pool size");
        return;
    }
    Block *start = memory;
    start->size = size - sizeof(Block);
    start->is_free = 1;
    start->next = NULL;
    freeList=start;
}
}
void *my_malloc(size_t size)
{   
    Block *current = freeList;
     while(current!= NULL)
        {   if(current->size <= size && current->is_free != 1)
            {
                current = current->next;
                continue;
            }
            else{
                if(current->size==size)
                {   if(current == freeList)
                    {
                        current->is_free = 0;
                        Block *newFree = current->next;
                        freeList = newFree;
                        break;
                    }
                    else{
                    current->is_free = 0;
                    Block *replace = freeList;
                    while(replace != NULL &&  replace->next != current)
                    {
                        replace = replace->next;
                    }
                    replace->next = current->next;
                    break;
                }
                
            }
        }
    }
            
    
}


