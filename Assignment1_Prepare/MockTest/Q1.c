#include <stdio.h>
void printBinary(unsigned int num){
    if (num > 1){
        printBinary(num/2);
    }
    printf("%d", num % 2);
}

int main(){
    unsigned int sampleNum = 0b10100011111010111011111100010101;
    printBinary(sampleNum);
    int temp1 = ((0b1111<<4) & sampleNum)>>4;
    int temp2 = ((0b1111<<10) & sampleNum)>>10;

    sampleNum &= ~((0b1111<<4)|(0b1111<<10));
    sampleNum |= ((temp2<<4));
    sampleNum |= (temp1<<10);
    printf("\n");
    printBinary(sampleNum);

}