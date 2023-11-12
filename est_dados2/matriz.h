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

typedef struct ListaDuplamenteEncadeada {
    Celula* cabeca;
    int linha;
    int coluna;
} ListaDuplamenteEncadeada;


void inicializaMatriz(struct Matriz* matriz, int nlin, int ncol);
void insereCelula(ListaDuplamenteEncadeada *lista, int linha, int coluna, float valor);
Matriz leMatriz(FILE *file);
void imprimeMatriz(Matriz A);
Matriz somaMatrizes(Matriz A, Matriz B);
Matriz multiplicaMatrizes(Matriz A, Matriz B);
Celula *buscaCelula(Matriz *mat, int linha, int coluna);

#endif
