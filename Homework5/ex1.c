#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements in the array \n");
    scanf("%d", &n);

    int* arr = (int*)(malloc(n * sizeof(int)));

    if (!arr) {
        perror("Memory allocation failed");
        return 1;
    }

    printf("Enter %d integers \n", n);
    int el;
    int result = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &el);

        arr[i] = el;
        result += el;
    }

    printf("The sum of numbers is %d \n", result);

    free(arr);

    return 0;
}