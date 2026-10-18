#include <stdlib.h>
#include <stdio.h>

struct Struct1 {
    char a;
    int b;
    double c;
};

struct Struct2 {
    double a;
    int b;
    char c;
};

int main() {
    struct Struct1 str1 = {'a', 5, 7.5};

    printf("Size of the struct: %zu bytes \n", sizeof(str1));
    printf("Address of double in struct: %p \n", &str1.a);
    printf("Address of int in struct: %p \n", &str1.b);
    printf("Address of char in struct: %p \n", &str1.c);

    struct Struct2 str2 = {7.5, 5, 'a'};

    printf("Size of the struct: %zu bytes \n", sizeof(str2));
    printf("Address of char in struct: %p \n", &str2.a);
    printf("Address of int in struct: %p \n", &str2.b);
    printf("Address of double in struct: %p \n", &str2.c);

    return 0;
}