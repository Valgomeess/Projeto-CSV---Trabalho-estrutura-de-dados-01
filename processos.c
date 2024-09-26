#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processos.h"

// Fun√ß√£o para ler os dados do arquivo e armazenar no vetor de structs
int ler_dados(char *nome_arquivo, Processo processos[], int tamanho) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }
    
    // Ignorando a primeira linha 
    char linha[200];
    fgets(linha, sizeof(linha), arquivo);

    int i = 0;
    while (fgets(linha, sizeof(linha), arquivo) != NULL && i < tamanho) {
        // Usando strtok para separar os campos da linha
        char *token = strtok(linha, ",");
        processos[i].id = atoi(token);  // Convertendo o id para inteiro
        
        token = strtok(NULL, ",");
        strcpy(processos[i].numero, token);  // Copiando o n√∫mero do processo
        
        token = strtok(NULL, ",");
        strcpy(processos[i].data_ajuizamento, token);  // Copiando a data de ajuizamento
        
        token = strtok(NULL, ",");
        processos[i].id_classe = atoi(token);  // Convertendo o id_classe para inteiro
        
        token = strtok(NULL, ",");
        processos[i].id_assunto = atoi(token);  // Convertendo o id_assunto para inteiro
        
        token = strtok(NULL, ",");
        processos[i].ano_eleicao = atoi(token);  // Convertendo o ano da elei√ß√£o para inteiro
        
        i++;
    }
    
    fclose(arquivo);
    return i;  // Retorna o n√∫mero de processos lidos
}

// FunÁ„o para ordenar os processos pelo campo 'id' em ordem crescente
void ordenar_por_id(Processo processos[], int tamanho) {
    Processo temp;
    int i, j;  // Declare as vari·veis fora dos loops
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (processos[j].id > processos[j + 1].id) {
                temp = processos[j];
                processos[j] = processos[j + 1];
                processos[j + 1] = temp;
            }
        }
    }
}

void imprimir_processos(Processo processos[], int tamanho) {
    int i;  // Declare a vari·vel fora do loop
    for (i = 0; i < tamanho; i++) {
        printf("ID: %d, Numero: %s, Data: %s, Classe: %d, Assunto: %d, Ano: %d\n",
               processos[i].id, processos[i].numero, processos[i].data_ajuizamento,
               processos[i].id_classe, processos[i].id_assunto, processos[i].ano_eleicao);
    }
}
