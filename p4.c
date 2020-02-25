#include <stdio.h>

int customPow(int base, int power);

int main() {
    int x, n;
    printf("Ingrese 2 números x y n para calcular la sumatoria de x^i con i = 0 hasta i = n\n");
    printf("Ingrese x: ");
    scanf("%d", &x);
    printf("\nIngrese n:");
    scanf("%d", &n);
    int sum = 0;
    for (int power = 0; power <= n; power++) {
        sum += customPow(x, power);
    }
    printf("El resultado es %d", sum);
    return 0;
}

int customPow(int base, int power) {
    int result = 1;
    for (int i = 0; i < power; i++) {
        result *= base;
    }
    return result;
}