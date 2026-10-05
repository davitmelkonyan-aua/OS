#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of students in the class \n");
    scanf("%d", &n);

    int* arr = (int*)(malloc(n * sizeof(int)));

    if (!arr) {
        perror("Memory allocation failed \n");
        return 1;
    }

    printf("Enter the grades of children \n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);   
    }

    int max = 0, min = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("\nHighest grade: %d \n", max);
    printf("Lowest grade: %d \n", min);

    free(arr);

    return 0;
}   