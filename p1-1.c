#include <stdio.h>

double calculateComission(int quarterlySale);

// Harry's Car Sales
int main() {
    int salesValues[7] = {20000, 20001, 30000, 50000, 50001, 75000, -3};
    double calculatedComission;
    for(int salesIndex = 0; salesIndex < sizeof(salesValues)/sizeof(int); salesIndex++) {
        calculatedComission = calculateComission(salesValues[salesIndex]);
        printf("El valor calculado de comisión para la venta %d es %10.3f\n", salesValues[salesIndex], calculatedComission);
    }
    return 0;
}

double calculateComission(int quarterlySale) {
    static const int firstLowerBound = 0;
    static const int firstUpperBound = 20000;
    static const int secondUpperBound = 50000;
    float comissionPercentage;
    int bonus;
    if(quarterlySale >= firstLowerBound && quarterlySale <= firstUpperBound) {
        comissionPercentage = 0.05;
        return (double) quarterlySale * comissionPercentage;
    } else if (quarterlySale > firstUpperBound && quarterlySale <= secondUpperBound) {
        comissionPercentage = 0.07;
        bonus = 1000;
        return (double) quarterlySale * comissionPercentage + bonus;
    } else if (quarterlySale > secondUpperBound) {
        comissionPercentage = 0.1;
        bonus = 3100;
        return (double) quarterlySale * comissionPercentage + bonus;
    } else {
        printf("Ingresaste un valor de ventas negativo, debe ser positivo :c\n");
        return (double) 0;
    }
}