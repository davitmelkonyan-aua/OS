#include <stdlib.h>
#include <stdio.h>

#define n 10

int main() {
    int* arr = (int*)(malloc(n * sizeof(int)));

    if (!arr) {
        perror("Memory allocation failed");
        return 1;
    }

    printf("Enter %d integers \n", n);
    int el;

    for (int i = 0; i < n; i++) {
        scanf("%d", &el);

        arr[i] = el;
    }

    printf("The array before shrinking with realloc \n");

    for(int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }

    arr = (int*)(realloc(arr, 5 * sizeof(int)));

    printf("\nThe array after shrinking with realloc \n");

    for(int i = 0; i < 5; i++) {
        printf("%d, ", arr[i]);
    }

    printf("\n");

    free(arr);

    return 0;
}