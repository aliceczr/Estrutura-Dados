#include "poligono.h"
#include <stdio.h>
#include <stdlib.h>

Poligono *criarPoligono(int numVertices) {
    Poligono *poligono = (Poligono *)malloc(sizeof(Poligono));
    if (poligono == NULL) {
        printf("Erro ao alocar a memoria para o polígono.\n");
        exit(1);
    }

    poligono->numVertices = numVertices;
    poligono->vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));
    if (poligono->vertices == NULL) {
        printf("Erro ao alocar a memoria para os vertices do poligono.\n");
        exit(1); // Você deve sair do programa em caso de erro de alocação.
    }
    return poligono;
}

void destruirPoligono(Poligono *poligono) {
    free(poligono->vertices);
    free(poligono);
}

void lerVertices(Poligono *poligono, const char *arquivo) {
    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", arquivo);
        exit(1);
    }
    for (int i = 0; i < poligono->numVertices; i++) {
        fscanf(file, "%f %f", &poligono->vertices[i].x, &poligono->vertices[i].y);
    }
    fclose(file);
}

float calcularArea(Poligono *poligono) {
    float area = 0.0;
    for (int i = 0; i < poligono->numVertices; i++) {
        int j = (i + 1) % poligono->numVertices;
        area += (poligono->vertices[i].x * poligono->vertices[j].y) -
                (poligono->vertices[j].x * poligono->vertices[i].y);
    }

    area = 0.5 * (area < 0 ? -area : area);

    return area;
}
