#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct {
    int* arr;
    int start;
    int end;
} params;

void* print_numbers(void* args) {
    printf("The result of thread %ld is: ", (long)pthread_self());

    for (int i = 1; i <= 5; i++) {
        printf("%d, ", i);
    }

    printf("\n");

    return NULL;
}

int main() {
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, print_numbers, NULL);
    pthread_create(&t2, NULL, print_numbers, NULL);
    pthread_create(&t3, NULL, print_numbers, NULL);


    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}