#include <stdlib.h>
#include <stdio.h>

int main() {
    int a = 5;
    char b = 'a';
    double c = 7.5;
    short d = 3;

    printf("Size of int: %zu bytes and the address is %p \n", sizeof(a), &a);
    printf("Size of char: %zu bytes and the address is %p \n", sizeof(b), &b);
    printf("Size of double: %zu bytes and the address is %p \n", sizeof(c), &c);
    printf("Size of short: %zu bytes and the address is %p \n", sizeof(d), &d);

    return 0;
}