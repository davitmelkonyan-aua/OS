#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements in the array \n");
    scanf("%d", &n);

    int* arr = (int*)(calloc(n, sizeof(int)));

    if (!arr) {
        perror("Memory allocation failed");
        return 1;
    }

    printf("Initially the values of elements are \n");

    for(int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }

    printf("\nEnter %d integers \n", n);
    int el;
    int result = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &el);

        arr[i] = el;
        result += el;
    }

    printf("Finally the values of elements are \n");

    for(int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }

    printf("\nThe average of the nummers is %f \n", (float)result / n);

    free(arr);

    return 0;
}