#include <stdio.h>

int main() {
    int nLines;
    printf("Ingrese el número de renglones a imprimir: ");
    scanf("%d", &nLines);
    printf("\n");
    for (int line = 0; line < nLines; line++) {
        for (int binNode = 0; binNode < line + 1; binNode++) {
            char digitToPrint;
            digitToPrint = ((binNode + line) % 2 == 0) ? '1' : '0';
            printf("%c", digitToPrint);
        }
        printf("\n");
    }
    return 0;
}