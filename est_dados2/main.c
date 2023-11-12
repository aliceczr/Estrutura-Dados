#include <stdio.h>
#include <stdlib.h> 
#include "matriz.h"

int main(void) {
    Matriz A, B, C, D;

    FILE *fileA, *fileB;
    fileA = fopen("matrizA.txt", "r");
    fileB = fopen("matrizB.txt", "r");

    if (fileA == NULL || fileB == NULL) {
        printf("Erro ao abrir os arquivos de entrada.\n");
        return 1;
    }

    A = leMatriz(fileA);
    B = leMatriz(fileB);

    fclose(fileA);
    fclose(fileB);

    printf("Matriz A:\n");
    imprimeMatriz(A);
    printf("\n");

    printf("Matriz B:\n");
    imprimeMatriz(B);
    printf("\n");

    C = somaMatrizes(A, B);

    printf("Resultado da Soma (Matriz C):\n");
    imprimeMatriz(C);
    printf("\n");

    D = multiplicaMatrizes(A, B); 
    printf("Resultado da Multiplicação (Matriz D):\n");
    imprimeMatriz(D);
    printf("\n");

    return 0;
}
