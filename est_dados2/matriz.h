#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct Celula {
    struct Celula *direita, *abaixo;
    int linha, coluna;
    float valor;
    struct Celula* antecessor;
    struct Celula* sucessor;
} Celula;

typedef struct {
    Celula *cabeca;
    int nlin, ncol;
} Matriz;

typedef struct ListaDuplamenteEncadeada {
    Celula* cabeca;
    int linha;
    int coluna;
} ListaDuplamenteEncadeada;

void insere(Matriz *A, int i, int j, float v);
Matriz leMatriz();
void imprimeMatriz(Matriz A);
Matriz somaMatrizes(Matriz A, Matriz B);
Matriz multiplicaMatrizes(Matriz A, Matriz B);
#endif
