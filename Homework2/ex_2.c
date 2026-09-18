#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/wait.h>

int main() {

    printf("The parent process starts \n");

    pid_t pid1 = fork();

    if (pid1 < 0) {
        perror("The forking failed \n");
    } else if (pid1 == 0) {
        execl("/usr/bin/ls", "ls", NULL);
    } 
    
    wait(NULL);

    pid_t pid2 = fork();

    if (pid2 < 0) {
        perror("The forking failed \n");
    } else if (pid2 == 0) {
        execl("/usr/bin/date", "date", NULL);
    }
        
    wait(NULL);  
    printf("Parent process done \n");

    return 0;
}