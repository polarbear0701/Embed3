#include <stdio.h>

// Function to print binary representation of an integer
void printBinary(unsigned int num) {
    if (num > 1)
        printBinary(num / 2);
    printf("%d", num % 2);
}

int main() {
    // unsigned int num = 10; // Your integer variable

    // printf("Binary representation of %d is: ", num);
    // printBinary(num);
    // printf("\n");
    unsigned int num = 0b10100111101111111000110001100101;
    int first_six = num & (0b111111);
    num = num >> 6;
    num = num << 10;
    int insertC = 0b1010;
    num = num | (insertC << 6);
    num = num | (first_six);

    printBinary(num);

    // printf("\n%d", num);

    return 0;
}