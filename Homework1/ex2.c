#include <stdio.h>

int main() {
    int nums[5] = {1, 2, 3, 4, 5};

    int* ptr = &nums[0];

    for (int i = 0; i < 5; i++) {
        printf("Element N%d is %d \n", i + 1, *(ptr + i));

        *(ptr + i) *= 10;
    }

    printf("After the change, via pointers \n");

    for (int i = 0; i < 5; i++) {
        printf("Element N%d is %d \n", i + 1, *(ptr + i));
    }

    printf("After the change, via array name \n");

    for (int i = 0; i < 5; i++) {
        printf("Element N%d is %d \n", i + 1, nums[i]);
    }
}