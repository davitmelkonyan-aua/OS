#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


void exitFunction1() {
    printf("Some exit functionality \n");
}

void exitFunction2() {
    printf("Some more exit functionality \n");
}

int main() {  

    atexit(exitFunction2);
    atexit(exitFunction1);

    printf("Doing some work \n");

    exit(0);
}


// Both functions must be registered before the call to exit() otherwise they will not be called

// Registration works with LIFO principle, meaning the last one to be registered will be the first one to be called