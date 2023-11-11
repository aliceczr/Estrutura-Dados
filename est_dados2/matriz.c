#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

void insere(Matriz *A, int i, int j, float v){
    // Implemente a inserção de uma célula na matriz A
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->linha = i;
    nova->coluna = j;
    nova->valor = v;

    // Inserir a célula na lista da linha i
    nova->direita = A->cabeca->direita;
    A->cabeca->direita = nova;

    // Inserir a célula na lista da coluna j
    nova->abaixo = A->cabeca->abaixo;
    A->cabeca->abaixo = nova;
}

Matriz leMatriz(const char *nomeArquivo){
    Matriz A;
    FILE *file;
    int m, n;
    int i, j;
    float valor;

    file = fopen(nomeArquivo, "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo de entrada: %s\n", nomeArquivo);
        exit(1);
    }

    fscanf(file, "%d, %d", &m, &n);
    A.nlin = m;
    A.ncol = n;

    A.cabeca = (Celula *)malloc(sizeof(Celula));
    A.cabeca->linha = -1;
    A.cabeca->coluna = -1;
    A.cabeca->direita = A.cabeca;
    A.cabeca->abaixo = A.cabeca;

    while (fscanf(file, "%d, %d, %f", &i, &j, &valor) == 3) {
        insere(&A, i, j, valor);
    }

    fclose(file);
    return A;
}

void imprimeMatriz(Matriz A){
    Celula *linha_atual = A.cabeca->abaixo;
    for (int i = 0; i < A.nlin; i++) {
        Celula *celula_atual = linha_atual->direita;
        for (int j = 0; j < A.ncol; j++) {
            if (celula_atual != linha_atual) {
                printf("%.2f\t", celula_atual->valor);
                celula_atual = celula_atual->direita;
            } else {
                printf("0.00\t"); // Elemento zero
            }
        }
        printf("\n");
        linha_atual = linha_atual->abaixo;
    }
}

Matriz somaMatrizes(Matriz A, Matriz B){
    if (A.nlin != B.nlin || A.ncol != B.ncol) {
        printf("As matrizes não têm as mesmas dimensões. A soma não é possível.\n");
        exit(1);
    }

    Matriz C;
    C.nlin = A.nlin;
    C.ncol = A.ncol;

    // Inicialize a matriz C com zeros
    C.cabeca = (Celula *)malloc(sizeof(Celula));
    C.cabeca->linha = -1;
    C.cabeca->coluna = -1;
    C.cabeca->direita = C.cabeca;
    C.cabeca->abaixo = C.cabeca;

    Celula *celulaA = A.cabeca->abaixo->direita;
    Celula *celulaB = B.cabeca->abaixo->direita;

    while (celulaA != A.cabeca || celulaB != B.cabeca) {
        int linhaA = (celulaA != A.cabeca) ? celulaA->linha : A.nlin;
        int colunaA = (celulaA != A.cabeca) ? celulaA->coluna : A.ncol;
        float valorA = (celulaA != A.cabeca) ? celulaA->valor : 0.0;

        int linhaB = (celulaB != B.cabeca) ? celulaB->linha : B.nlin;
        int colunaB = (celulaB != B.cabeca) ? celulaB->coluna : B.ncol;
        float valorB = (celulaB != B.cabeca) ? celulaB->valor : 0.0;

        if (linhaA == linhaB && colunaA == colunaB) {
            float soma = valorA + valorB;
            if (soma != 0.0) {
                insere(&C, linhaA, colunaA, soma);
            }
            celulaA = celulaA->direita;
            celulaB = celulaB->direita;
        } else if ((linhaA < linhaB) || (linhaA == linhaB && colunaA < colunaB)) {
            insere(&C, linhaA, colunaA, valorA);
            celulaA = celulaA->direita;
        } else {
            insere(&C, linhaB, colunaB, valorB);
            celulaB = celulaB->direita;
        }
    }

    return C;
}


Matriz multiplicaMatrizes(Matriz A, Matriz B){
    if (A.ncol != B.nlin) {
        printf("As dimensões das matrizes não são compatíveis para multiplicação.\n");
        exit(1);
    }

    Matriz C;
    C.nlin = A.nlin;
    C.ncol = B.ncol;

    // Inicialize a matriz C com zeros
    C.cabeca = (Celula *)malloc(sizeof(Celula));
    C.cabeca->linha = -1;
    C.cabeca->coluna = -1;
    C.cabeca->direita = C.cabeca;
    C.cabeca->abaixo = C.cabeca;

    Celula *linhaA = A.cabeca->abaixo->abaixo;
    Celula *colunaB = B.cabeca->direita->direita;

    while (linhaA != A.cabeca) {
        while (colunaB != B.cabeca) {
            int i = linhaA->linha;
            int j = colunaB->coluna;
            float soma = 0.0;

            Celula *celulaA = linhaA->direita;
            Celula *celulaB = colunaB->abaixo;

            while (celulaA != linhaA && celulaB != colunaB) {
                if (celulaA->coluna == celulaB->linha) {
                    soma += celulaA->valor * celulaB->valor;
                    celulaA = celulaA->direita;
                    celulaB = celulaB->abaixo;
                } else if (celulaA->coluna < celulaB->linha) {
                    celulaA = celulaA->direita;
                } else {
                    celulaB = celulaB->abaixo;
                }
            }

            if (soma != 0.0) {
                insere(&C, i, j, soma);
            }

            colunaB = colunaB->direita;
        }

        linhaA = linhaA->abaixo;
    }

    return C;
}
