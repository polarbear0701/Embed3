#include <stdio.h>

void printBinary(unsigned int num){
    if (num > 1){
        printBinary(num/2);
    }
    printf("%d", num % 2);
}

int main(){
    unsigned int X = 0b10101111001110000011101101010111;
    // printBinary(X);
    int insertNum = 0b1010;
    int firstSix = 0b111111 & X;

    X = (X>>6) << 10;
    X |= ((insertNum<<6) | (firstSix<<0));
    printBinary(X);

}