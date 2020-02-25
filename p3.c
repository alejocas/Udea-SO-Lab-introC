#include <stdio.h>

int multiplo(int num1, int num2);

int main() {
    printf("Ingrese un 2 números pares separados por un espacio: [ej: 2 4]\n");
    int num1, num2, isMult;
    scanf("%d %d", &num1, &num2);
    isMult = multiplo(num1, num2);
    if(isMult) printf("%d es múltiplo de %d", num2, num1);
    else printf("%d no es múltiplo de %d", num2, num1);
    return 0;
}

int multiplo(int num1, int num2) {
    return (num2 % num1 == 0) ? 1 : 0;
}