#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

int main() {

    printf("Process ID: %ld, Parent Process ID: %ld \n", (intmax_t)getpid(), (intmax_t)getppid());
    pid_t originalpid = getpid();

    pid_t a = fork();

    if (a < 0) {
        perror("The forking failed \n");
        exit(EXIT_FAILURE);
    }
 
    printf("After 1 fork: Process ID: %ld, Parent Process ID: %ld \n", (intmax_t)getpid(), (intmax_t)getppid());

    pid_t b = fork();

    if (b < 0) {
        perror("The forking failed \n");
        exit(EXIT_FAILURE);
    }

    printf("After 2 fork: Process ID: %ld, Parent Process ID: %ld \n", (intmax_t)getpid(), (intmax_t)getppid());
 
    pid_t c = fork();

    if (c < 0) {
        perror("The forking failed \n");
        exit(EXIT_FAILURE);
    }

    printf("After 3 fork: Process ID: %ld, Parent Process ID: %ld \n", (intmax_t)getpid(), (intmax_t)getppid());
 

    if (getpid() == originalpid) {
        printf("There are 15 prints, as we have a parent process, which creates a child process, then both of them create a process each and then the 4 of them create a process each, so we get 8 processes");
    }

    return 0; 
}