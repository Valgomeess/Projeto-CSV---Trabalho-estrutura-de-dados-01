#ifndef PROCESSOS_H
#define PROCESSOS_H

// Definindo a estrutura para armazenar os dados de cada processo
typedef struct {
    int id;
    char numero[21];
    char data_ajuizamento[30];
    int id_classe;
    int id_assunto;
    int ano_eleicao;
} Processo;

// Funções para manipular os processos
int ler_dados(char *nome_arquivo, Processo processos[], int tamanho);
void ordenar_por_id(Processo processos[], int tamanho);
void imprimir_processos(Processo processos[], int tamanho);

#endif
