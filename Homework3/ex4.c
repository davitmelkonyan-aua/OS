#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {  
    pid_t pid1 = fork();
    int status1;

    if (pid1 == 0) {
        printf("Child process 1 \n");
        exit(0);
    }

    waitpid(pid1, &status1, 0);

    pid_t pid2 = fork();
    int status2;

    if (pid2 == 0) {
        printf("Child process 2 \n");
        exit(1);
    }

    waitpid(pid2, &status2, 0);

    if (WIFEXITED(status1)) {
        printf("Child 1 exited normally \n");
    } else {
        printf("Child 1 exited with an error \n");
    }

    if (WIFEXITED(status2)) {
        printf("Child 2 exited normally \n");
    } else {
        printf("Child 2 exited with an error \n");
    }

    return 0;
}