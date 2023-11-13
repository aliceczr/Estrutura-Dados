#ifndef MATRIZ_H
#define MATRIZ_H
#include <stdio.h>

typedef struct Celula {
    struct Celula *direita, *abaixo;
    int linha, coluna;
    float valor;
} Celula;

typedef struct Matriz {
    Celula *cabeca;
    int nlin, ncol;
} Matriz;



void inicializaMatriz(struct Matriz* matriz, int nlin, int ncol);
void insere(Matriz *A, int i, int j, float v);
Matriz leMatriz(FILE *file);
void imprimeMatriz(Matriz A);
Matriz somaMatrizes(Matriz A, Matriz B);
Matriz multiplicaMatrizes(Matriz A, Matriz B);
Celula *buscaCelula(Matriz *mat, int linha, int coluna);

#endif
