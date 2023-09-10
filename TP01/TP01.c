#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define MAX_FIELD_LENGTH 1024
#define MAX_LINE_LENGTH 256

typedef struct 
{
    char nome[100];
    char telefone[25];
    char curso[30];
    float nota1, nota2;
    float media;
    char status[20];
} Aluno;

float result(float n1, float n2) {
    return (n1 + n2) / 2.0;
}    

int main() {
    FILE *file = fopen("C:\\Users\\mackl\\Documents\\programing\\Dados Estruturados\\DadosEntrada.csv", "r");

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char line[MAX_LINE_LENGTH];

    FILE *outputFile = fopen("TP01.csv", "a");

    fprintf(outputFile, "Nome,Media,Status\n");

    if (outputFile == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

    printf("Iniciando o loop de leitura e escrita...\n");

    while (fgets(line, sizeof(line), file)) {
        printf("Lendo linha: %s\n", line);
        
        Aluno aluno;
        char *token;
        char *rest = line;

        token = strtok(rest, ",");

        if (token == NULL) {
            continue;
        }
        strncpy(aluno.nome, token, MAX_FIELD_LENGTH);

        token = strtok(NULL, ",");

        if (token == NULL) {
            continue;
        }
        strncpy(aluno.telefone, token, MAX_FIELD_LENGTH);

        token = strtok(NULL, ",");

        if (token == NULL) {
            continue;
        }
        strncpy(aluno.curso, token, MAX_FIELD_LENGTH);

        token = strtok(NULL, ",");

        if (token == NULL) {
            continue;
        }
        sscanf(token, "%f", &aluno.nota1);

        token = strtok(NULL, ",");

        if (token == NULL) {
            continue;
        }

        sscanf(token, "%f", &aluno.nota2);

        aluno.media = result(aluno.nota1, aluno.nota2);

        if (aluno.media >= 7.0) {
            strcpy(aluno.status, "APROVADO");
        } else {
            strcpy(aluno.status, "REPROVADO");
        }
        
        printf("Escrevendo dados no arquivo: %s, %.2f, %s\n", aluno.nome, aluno.media, aluno.status);
        fprintf(outputFile, "%s,%.2f,%s\n", aluno.nome, aluno.media, aluno.status);
    }   

    fclose(file);
    fclose(outputFile);


    return 0;
}
