#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void* print_message(void* args) {
    const pthread_t tid = pthread_self();
    printf("Thread %ld is running \n", (long)tid);
}

int main() {
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, print_message, NULL);
    pthread_create(&t2, NULL, print_message, NULL);
    pthread_create(&t3, NULL, print_message, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}