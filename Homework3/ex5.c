#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {  
    pid_t pid1 = fork();

    if (pid1 == 0) {
        sleep(6);
        printf("Child process 1 \n");
        exit(0);
    }

    wait(NULL);

}