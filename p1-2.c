#include <stdio.h>

int main() {
    int maxNumber;
    printf("Numero final (empezando de 1): ");
    scanf("%d", &maxNumber);
    printf("Tabla de multiplicación desde 1 hasta %d\n", maxNumber);
    int iterations = 0;
    do {
        for(int i = 1; i <= maxNumber; i++){
            printf("%dx%d = %d, ", i, iterations + 1, i * (iterations + 1));
        }
        printf("\n");
        iterations++;
    } while (iterations < 10);
    return 0;
}