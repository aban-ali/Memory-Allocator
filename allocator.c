#include "allocator.h"
#include <stdio.h>

static char memory_pool[MEMORY_SIZE];
static block_t* free_list = NULL;

void init_allocator(){
    free_list = (block_t*) memory_pool;
    free_list->size = MEMORY_SIZE - sizeof(block_t);
    free_list->free = 1;
    free_list->next = NULL;
}


void* my_malloc(size_t size){
    block_t *curr = free_list;

    while(curr){
        if(curr->free && curr->size >= size){
            if(curr->size >= sizeof(block_t) + size + 1){

                block_t* block = (block_t*)((char*)curr + sizeof(block_t) + size);

                block->size = curr->size - size - sizeof(block_t);
                block->free = 1;
                block->next = curr->next;

                curr->size = size;
                curr->next = block;
                // printf("Memory LEFT : %lu\n", block->size);
            }
            curr->free = 0;
            // printf("Space Allocated\n");
            return (void*)(curr + 1);
        }
        curr = curr->next;
    }
    // printf("No space is there of size: %lu....\n", size);
    return NULL;
}


void my_free(void* ptr){
    if(!ptr) return;

    block_t* block = (block_t*)ptr - 1;
    block->free = 1;
    block_t* curr = free_list;
    block_t* prev = NULL;
    
    //finding the previous block wrt current one.
    while(curr && curr != block){
        prev = curr;
        curr = curr->next;
    }

    // if previous block is free then coalescing memory
    if(prev && prev->free){
        prev->size += sizeof(block_t) + block->size;
        prev->next = block->next;
        block = prev;
    }

    block_t* next = block->next;
    while(next && next->free){
        block->size += sizeof(block_t) + next->size;
        block->next = next->next;
        next = block->next;
    }
}