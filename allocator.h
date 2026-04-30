



typedef struct block {
    size_t size;
    int free;
    struct block* next;
} block_t;