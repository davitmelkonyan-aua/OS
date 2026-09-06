#include <stdio.h>

int main() {
    char str[] = "Hello";   

    char *ptr = str;

    for (int i = 0; i < 5; i++) {
        printf("%c", *(str + i));
    }

    printf("\n");


    ptr = str;  // 

    int count = 0;

    while (*(ptr + count) != '\0')
    {
        count++;
    }

    printf("Number of characters: %d\n", count);
}