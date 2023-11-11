#include <stdio.h>
#include <stdlib.h> 
#include "matriz.h"

int main(void){

    Matriz A, B, C, D;

    A = leMatriz("arquivoA.txt");
    B = leMatriz("arquivoB.txt");

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
