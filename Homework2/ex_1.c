#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

    printf("The parent process starts \n");

    pid_t pid = fork();

    if (pid == 0) {
        execl("/usr/bin/ls", "ls", NULL);

        perror("execl failed");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("The forking failed \n");
    } else {
        wait(NULL);
        printf("Parent process done \n");
    }


    return 0;
}