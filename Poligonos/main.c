#include <stdio.h>
#include "poligono.h"

int main() {
    int numVertices;
   

    printf("Digite o número de vértices do polígono: ");
    scanf("%d", &numVertices);

    Poligono *poligono = criarPoligono(numVertices);
    
    printf("Digite o nome do arquivo com as coordenadas dos vértices: ");
    char nomeArquivo[100];
    scanf("%s", nomeArquivo);

    lerVertices(poligono, nomeArquivo);
    float area = calcularArea(poligono);

    printf("A área do polígono é %.2f\n", area);

    destruirPoligono(poligono);

    return 0;
}
