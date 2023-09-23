#ifndef POLIGONO_H
#define POLIGONO_H

#include "ponto.h"

typedef struct 
{
    int numVertices;
    Ponto *vertices;
}Poligono;

Poligono *criarPoligono(int numVetices);
void destruirPoligono(Poligono *poligono);
void lerVertices(Poligono *poligono, const char *arquivo);
float calcularArea(Poligono *poligono);

#endif