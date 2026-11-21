#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* calculate_square(void* args) {
    int* number = (int*)args;

    int square = *number * *number;

    printf("Square of %d is %d\n", *number, square);

    return NULL;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    pthread_t threads[5];

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, calculate_square, &arr[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}