#include <stdio.h>

int main() {
    int a = 5;

    int *ptr = &a;
    int **dptr = &ptr;

    printf("The value of the variabe using pointer %d \n", *ptr);
    printf("The value of the variabe using double pointer %d \n", **dptr);
}

