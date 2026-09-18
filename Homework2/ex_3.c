#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>

int main() {

    printf("The parent process starts \n");

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork error");
    } else if (pid == 0) {
        execl("/usr/bin/echo", "echo", "Hello from the child process", NULL);
    }

    wait(NULL);

    printf("The parent process ends \n");
}