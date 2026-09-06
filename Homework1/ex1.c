#include <stdio.h>

int main() {
    int a = 5;
    int *ptr_a = &a;

    printf("The value of the variable via itself: %d \n", a);
    printf("The value of the variable via pointer: %d \n", *ptr_a);

    *ptr_a = 10;

    printf("The new value of the variable: %d \n", *ptr_a);
}