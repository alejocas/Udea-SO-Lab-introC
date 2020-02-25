#include <stdio.h>
#include <stdlib.h> //rand() y srand()
#include <time.h>   //time()

int generateRandomNumber(int lowerBound, int upperBound);
int verifyAnswer(int realAnswer, int userAnswer);

int main() {
    srand(time(NULL)); //genera la semilla para números aleatorios
    int running = 1;
    printf("Bienvenido al software de educación más completo del mercado\n");
    while(running) {
        int attempt = 1;
        int pairOfNumbers[2] = {0, 0};
        int realAnswer = 1;
        for (int i = 0; i < sizeof(pairOfNumbers)/sizeof(int); i++) {
            pairOfNumbers[i] = generateRandomNumber(1, 10);
            realAnswer *= pairOfNumbers[i];
        }
        while(attempt) {
            int userAnswer;
            printf("¿Cuánto es %d veces %d? R/ ", pairOfNumbers[0], pairOfNumbers[1]);
            scanf("%d", &userAnswer);
            attempt = verifyAnswer(realAnswer, userAnswer);
        }
        printf("¿Desea continuar con más multiplicaciones?\n0. No\n1. Sí\n");
        scanf("%d", &running);
    }
}

int generateRandomNumber(int lowerBound, int upperBound) {
    int M, m;
    M = upperBound;
    m = lowerBound;
    return rand()%(M - m + 1) + m;
}

int verifyAnswer(int realAnswer, int userAnswer) {
    char successMessages[4][40] = {
        "Muy bien!\n",
        "Excelente!\n",
        "Buen trabajo!\n",
        "Sigue haciéndolo bien!\n"
    };
    char failureMessages[4][40] = {
        "No. Por favor trata de nuevo.\n",
        "Incorrecto. Trata una vez más.\n",
        "No te rindas!\n",
        "No. Trata de nuevo\n"
    };
    const int SUCCESS_CODE = 0, FAILURE_CODE = 1;
    if(realAnswer == userAnswer) {
        printf(successMessages[generateRandomNumber(0,3)]);
        return SUCCESS_CODE;
    } else {
        printf(failureMessages[generateRandomNumber(0,3)]);
        return FAILURE_CODE;
    }
}