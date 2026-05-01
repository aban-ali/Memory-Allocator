#include <stdio.h>
#define MEMORY_SIZE 106

void        init_allocator();
void*       my_malloc(size_t size);
void        my_free(void* ptr);


typedef struct block {
    size_t size;
    int free;
    struct block* next;
} block_t;