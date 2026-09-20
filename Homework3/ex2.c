#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t pid1 = fork();
    int status1;

    if (pid1 == 0) {
        printf("The pid of first child process is: %d \n", getpid());
        exit(0);
    }
    
    wait(&status1);
    printf("The pid of parent process is: %d \n", getpid());

    pid_t pid2 = fork();
    int status2;

    if (pid2 == 0) {
        printf("The pid of second child process is: %d \n", getpid());
        exit(0);
    }

    waitpid(pid2, &status2, 0);

    printf("The status codes of child process are: %d, %d \n", status1, status2);

    return 0;
}