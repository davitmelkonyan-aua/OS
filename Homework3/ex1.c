#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    pid_t pid = fork();

    if (pid == 0) {
        printf("The pid of child process is: %d \n", getpid());
        exit(0);
    } else {
        printf("The pid of parent process is: %d \n", getpid());
    }

    return 0;
}