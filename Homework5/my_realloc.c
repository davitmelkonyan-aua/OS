#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* my_realloc(void* ptr, size_t oldSize, size_t newSize) {
    void* newPtr = malloc(newSize);

    if (!newPtr) {
        perror("Memory allocation failed");
        return NULL;
    }

    memcpy(newPtr, ptr, oldSize);
    free(ptr);

    return newPtr;
}

int main() {
    int* ptr = (int*)(malloc(3 * sizeof(int)));

    ptr[0] = 1;
    ptr[1] = 2;
    ptr[2] = 3;

    printf("Before realloc \n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", ptr[i]);
    }

    int* newPtr = (int *)(my_realloc(ptr, 3 * sizeof(int), 5 * sizeof(int)));

    newPtr[3] = 4;
    newPtr[4] = 5;
    
    printf("\nAfter realloc \n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", newPtr[i]);
    }
    printf("\n");

    free(newPtr);

    return 0;
}