#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define NUM_FILAS 3
#define QUANTUM 2

int ler_processos(const char* nome_arquivo, Processo** processos);

int main(int argc, char *argv[]) {
    // Inicializa três filas, uma para cada nível de prioridade
    Fila filas[NUM_FILAS] = {0};
    
    // Carregar processos de um arquivo txt
    Processo* processos = NULL;
    int num_processos = ler_processos("processos.txt", &processos);
    
    if (num_processos == 0) {
        printf("Nenhum processo carregado. Encerrando...\n");
        return 1;
    }

    /* CODIGO AQUI */

  return 0;
}

int ler_processos(const char* nome_arquivo, Processo** processos) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;  // Retorna 0 se não for possível abrir o arquivo
    }

    int num_processos = 0;
    Processo p;
    while (fscanf(arquivo, "%d %d %d", &p.id, &p.tempo_chegada, &p.tempo_servico) == 3) {
        p.tempo_restante = p.tempo_servico;  // Inicializa o tempo restante com o tempo_servico
        p.prioridade = 0;  // Inicializa a prioridade (0 para a fila de alta prioridade)
        
        (*processos) = realloc(*processos, (num_processos + 1) * sizeof(Processo));
        (*processos)[num_processos++] = p;
    }

    fclose(arquivo);
    return num_processos;
}