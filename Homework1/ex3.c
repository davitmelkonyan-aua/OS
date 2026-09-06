#include <stdio.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    int a = 5, b = 10;

    printf("The values of variables before the swap\n");
    printf("a: %d, b: %d \n", a, b);

    swap(&a, &b);

    printf("The values of variables after the swap\n");
    printf("a: %d, b: %d \n", a, b);
}

