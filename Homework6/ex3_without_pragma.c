#include <stdlib.h>
#include <stdio.h>

struct Struct {
    char a;
    int b;
    double c;
};

int main() {
    struct Struct str = {'a', 5, 7.5};

    printf("Size of the struct: %zu bytes \n", sizeof(str));
    printf("Address of double in struct: %p \n", &str.a);
    printf("Address of int in struct: %p \n", &str.b);
    printf("Address of char in struct: %p \n", &str.c);

    return 0;
}