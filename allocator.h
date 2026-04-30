#define MEMORY_SIZE 1024

typedef struct block {
    size_t size;
    int free;
    struct block* next;
} block_t;