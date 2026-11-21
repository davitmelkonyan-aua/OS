#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct {
    int* arr;
    int start;
    int end;
} params;

void* calculate_sum(void* args) {
    params* arguments = (params*)args;

    int sum = 0;

    for (int i = arguments->start; i <= arguments->end; i++) {
        sum += arguments->arr[i];
    }

    printf("The result of thread %ld is %d \n", (long)pthread_self(), sum);

    return NULL;
}

int main() {
    pthread_t t1, t2;

    int* arr = malloc(10 * sizeof(int));

    if (!arr) {
        perror("Malloc failed");
        exit(1);
    }

    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }

    params p1 = {arr, 0, 4};
    params p2 = {arr, 5, 9};

    pthread_create(&t1, NULL, calculate_sum, &p1);
    pthread_create(&t2, NULL, calculate_sum, &p2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    free(arr);

    return 0;
}