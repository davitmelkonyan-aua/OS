#include <stdlib.h>
#include <stdio.h>

int main() {
    char** arr = (char**)(malloc(3 * sizeof(char*)));

    if (!arr) {
        perror("Memory allocation failed \n");
        return 1;
    }

    printf("Enter 3 strings \n");

    for (int i = 0; i < 3; i++) {
        arr[i] = (char*)(malloc(50 * sizeof(char)));

        if (!arr[i]) {
            perror("Memory allocation failed \n");\
            return 1;
        }

        scanf("%49s", arr[i]);
    }

    for (int i = 0; i < 3; i++) {
        printf("String %d: %s \n", i + 1, arr[i]);
    }

    printf("\nNow print 2 more strings \n");

    arr = realloc(arr, 5 * sizeof(char *));

    if (!arr) {
        perror("Memory allocation failed \n");
        return 1;
    }

    for (int i = 3; i < 5; i++) {
        arr[i] = (char*)(malloc(50 * sizeof(char)));

        if (!arr[i]) {
            perror("Memory allocation failed \n");\
            return 1;
        }

        scanf("%49s", arr[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("String %d: %s \n", i + 1, arr[i]);

        free(arr[i]);
    }

    free(arr);

    return 0;
}    
