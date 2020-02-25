#include <stdio.h>
#include <stdlib.h> //rand() y srand()
#include <string.h>
#include <time.h>   //time()

int generateRandomNumber(int lowerBound, int upperBound);
void obtainAnswerMessages(char messages[][40], int success);
void showResults(int successAnswers, int failedAnswers);
int verifyAnswer(int realAnswer, int userAnswer, int* successAnswers, int* failedAnswers);

int main() {
    srand(time(NULL)); //genera la semilla para números aleatorios
    int running = 1;
    int successAnswers = 0, failedAnswers = 0;
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
            attempt = verifyAnswer(realAnswer, userAnswer, &successAnswers, &failedAnswers);
        }
        printf("¿Desea continuar con más multiplicaciones?\n0. No\n1. Sí\n");
        scanf("%d", &running);
    }
    printf("S: %d, F: %d\n", successAnswers, failedAnswers);
    showResults(successAnswers, failedAnswers);
}

int generateRandomNumber(int lowerBound, int upperBound) {
    int M, m;
    M = upperBound;
    m = lowerBound;
    return rand()%(M - m + 1) + m;
}

void obtainAnswerMessages(char messages[][40], int failure) {
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
    switch (failure) {
        case 0:
            memcpy(messages, successMessages, 4*40);
            break;
        default:
            memcpy(messages, failureMessages, 4*40);
            break;
    }
}

void showResults(int successAnswers, int failedAnswers) {
    int numberOfAttempts = successAnswers + failedAnswers;
    double successRate = successAnswers / numberOfAttempts;
    double failureRate = failedAnswers / numberOfAttempts;
    printf("-----------------------------------|\n");
    printf("| Item     | Cantidad | Porcentaje |\n");
    printf("-----------------------------------|\n");
    printf("| Aciertos | %3d      | %3.2f      |\n", successAnswers, successRate * 100);
    printf("| Fallos   | %3d      | %3.2f      |\n", failedAnswers, failureRate * 100);
    printf("| Total    | %3d      | %3.2f      |\n", numberOfAttempts, (successRate + failureRate) * 100);
    printf("-----------------------------------|\n");
    if(successRate < 0.75) {
        printf("Por favor pídele ayuda al instructor");
    }
}

int verifyAnswer(int realAnswer, int userAnswer, int *successAnswers, int *failedAnswers) {
    const int SUCCESS_CODE = 0, FAILURE_CODE = 1;
    char messages[4][40];
    char *message;
    if(realAnswer == userAnswer) {
        (*successAnswers)++;
        obtainAnswerMessages(messages, SUCCESS_CODE);
        message = messages[generateRandomNumber(0,3)];
        printf(message);
        return SUCCESS_CODE;
    } else {
        (*failedAnswers)++;
        obtainAnswerMessages(messages, FAILURE_CODE);
        message = messages[generateRandomNumber(0,3)];
        printf(message);
        return FAILURE_CODE;
    }
}