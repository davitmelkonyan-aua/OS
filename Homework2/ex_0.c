#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>

int main() {

    printf("Process ID: %ld, Parent Process ID: %ld \n", (intmax_t)getpid(), (intmax_t)getppid());

    pid_t a = fork();
 
    printf("After 1 fork: Process ID: %ld, Parent Process ID: %ld \n", (intmax_t)getpid(), (intmax_t)getppid());

    pid_t b = fork();

    printf("After 2 fork: Process ID: %ld, Parent Process ID: %ld \n", (intmax_t)getpid(), (intmax_t)getppid());
 
    pid_t c = fork();

    printf("After 3 fork: Process ID: %ld, Parent Process ID: %ld \n", (intmax_t)getpid(), (intmax_t)getppid());
 

    if (a > 0) {
        printf("There are 15 prints, as we have a parent process, which creates a child process, then both of them create a process each and then the 4 of them create a process each, so we get 8 processes");
    }

    return 0; 
}