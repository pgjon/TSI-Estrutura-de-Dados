#include <stdio.h>
#include <stdlib.h>
#include "FilaCF.h"

// procedimento para criar uma fila
void criaFila(FilaCF *fila) {
    fila->frente = 0;
    fila->re = -1;
}

// função para inserir um dado na fila
int insere(FilaCF *fila, Dado dado) {
    // Verifica primeiro se a fila ta cheia
    // Como re é o último dado a entrar na fila, tem que ser o ultimo a sair
    if (fila->re == MAX_NODOS - 1) {
        return FILA_CHEIA;  // como 'max_nodos' tem valor 5, quer dizer então, que o ultimo dado da fila tem  
                            // que ser o índice 4, por isso MAX_NODOS - 1 = 5 - 1 = 4
    }
    else { // caso a fila esteja vazia
        fila->re++; // incrementa re
        fila->v[fila->re] = dado; // adiciona o dado na fila
        return SUCESSO;
    }
}

// função para retirar dado da fila
int retira(FilaCF *fila, Dado *dado) {
    // Verifica se a fila está vazia
    if (fila->re == -1) {
        return FILA_VAZIA;
    }
    else {
        *dado = fila->v[fila->frente]; /* o endereço de dado recebe o valor do índice da frente da fila
                                       após, incrementa a frente, ou seja, tira da fila o valor que está no índice */
        fila->frente++; 
        return SUCESSO;
    }
}

// função para verificar se a fila está vazia
int estaVazia(FilaCF fila) {
    if (fila.re == -1)
        return FILA_VAZIA;
    else
        return SUCESSO;
}

// função para consultar o primeiro dado da fila
int consulta(FilaCF fila, Dado *dado) {
    // verifica se a fila está vazia
    if (fila.re == -1) {
        return FILA_VAZIA;
    }
    // caso não esteja vazia, o endereço de dado recebe o valor do índice da frente da fila
    else {
        *dado = fila.v[fila.frente];
        fila.frente++; // incrementa a frente, ou seja, tira da fila o valor que está no índice
        return SUCESSO;
    }
}

// procedimento para mostrar a fila
void exibe(FilaCF fila) {
    // verifica se a fila está vazia
    if (fila.re == -1) {
        printf("\nFila vazia!\n");
    }
    else {
        printf("\nFila: \n");
        for (int i = 0; i <= fila.re; i++) {
            printf("Código: %d - Peso: %.2f\n", fila.v[i].cod, fila.v[i].peso);
        }
    }
}
    
// função para consultar um dado atraves de um cod
int pesquisa(FilaCF fila, int cod, Dado *dado) {
    // verifica se a fila está vazia
    if (fila.re == -1) {
        return FILA_VAZIA;
    }
    // percorre a fila em busca do código
    for (int i = 0; i <= fila.re; i++) {
        if (fila.v[i].cod == cod) {
            *dado = fila.v[i];
            return SUCESSO;
        }
    }
    return DADO_INEXISTENTE;
}