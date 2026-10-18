#include <stdlib.h>
#include <stdio.h>

#pragma pack(1)
struct Struct1 {
    char a;
    int b;
    double c;
};

#pragma pack(2)
struct Struct2 {
    char a;
    int b;
    double c;
};

#pragma pack(4)
struct Struct4 {
    char a;
    int b;
    double c;
};

int main() {
    // 1 padding

    struct Struct1 str1 = {'a', 5, 7.5};

    printf("Size of the struct 1: %zu bytes \n", sizeof(str1));
    printf("Address of char in struct: %p \n", &str1.a);
    printf("Address of int in struct: %p \n", &str1.b);
    printf("Address of double in struct: %p \n", &str1.c);

    // 2 padding

    struct Struct2 str2 = {'a', 5, 7.5};

    printf("Size of the struct 2: %zu bytes \n", sizeof(str2));
    printf("Address of char in struct: %p \n", &str2.a);
    printf("Address of int in struct: %p \n", &str2.b);
    printf("Address of double in struct: %p \n", &str2.c);

    // 4 padding

    struct Struct4 str4 = {'a', 5, 7.5};

    printf("Size of the struct 4: %zu bytes \n", sizeof(str4));
    printf("Address of char in struct: %p \n", &str4.a);
    printf("Address of int in struct: %p \n", &str4.b);
    printf("Address of double in struct: %p \n", &str4.c);

    return 0;
}