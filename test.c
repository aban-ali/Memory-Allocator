#include "allocator.h"
#include <stdio.h>


int main(){
    init_allocator();
    int *a = (int*)my_malloc(sizeof(int));
    char* temp1 = (char*)my_malloc(sizeof(char));
    int *b = (int*)my_malloc(sizeof(int));
    char* temp2 = (char*)my_malloc(sizeof(char));
    int *c = (int*)my_malloc(sizeof(int)); // should not be allocated, when MEMORY_POOL is 106.
    printf("All allocated\n");
    my_free(temp1);
    my_free(b);
    char *temp = (char*)my_malloc(sizeof(char)*5);
    return 0;
}