#include <stdio.h>
#include <math.h>

int factorial(int num);

int main() {
    int x, n;
    printf("Ingrese 2 números x y n para calcular la sumatoria de los primeros n términos de (-1^n)*((x^(2*n))/n!)\n");
    printf("Valor de entrada de x: ");
    scanf("%d", &x);
    printf("Número de términos n:");
    scanf("%d", &n);
    float sum = 0;
    int sign;
    int fact;
    for (int power = 0; power <= n; power++) {
        int finalPow = 2 * power;
        sign = (power % 2 == 0) ? 1 : -1;
        fact = factorial(finalPow);
        sum += (float) sign * pow((double) x, (double) finalPow)/fact;
    }
    printf("suma %f", sum);
    return 0;
}

int factorial(int num) {
    return (num == 1 || num == 0) ? 1 : num * factorial(num - 1);
}