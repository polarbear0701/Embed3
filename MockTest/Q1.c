#include <stdio.h>
void printBinary(unsigned int num) {
    if (num > 1)
        printBinary(num / 2);
    printf("%d", num % 2);
}

int main(){
    unsigned int num = 0b10011000110010011111010101001010;
    printBinary(num);
    printf("\n");
    int temp74 = 0b1111, temp1013 = 0b1111;
    temp74 = ((temp74 << 4) & num) >> 4;
    temp1013 = ((temp1013 << 10) & num) >> 10;

    printBinary(temp1013);
    printf("\n");
    printBinary(temp74);
    printf("\n");

    num &= ~((0b1111 << 4)|(0b1111<<10));
    printBinary(num);
    printf("\n");

    num |= ((temp1013<<4) | (temp74<<10));
    printBinary(num);
    printf("\n");


    return 0;
}