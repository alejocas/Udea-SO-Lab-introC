#include <stdio.h>
#include <limits.h>

int reverseNumber(int num, int acc);

int main() {
    int numToReverse;
    int reversedNumber;
    printf("Ingrese un número (entre 0 y %d): ", INT_MAX);
    scanf("%d", &numToReverse);
    reversedNumber = reverseNumber(numToReverse, 0);
    printf("Número reversado: %d", reversedNumber);
    return 0;
}

int reverseNumber(int num, int acc) {
    if(num < 10) {
        return acc * 10 + num;
    } else {
        int remainder = num % 10;
        int dividedNum = (int) num / 10;
        return reverseNumber(dividedNum, acc * 10 + remainder);
    }
}