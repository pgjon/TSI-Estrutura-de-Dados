#include <stdio.h>
#include <stdlib.h>
#include "PilhaSE.h"

void criaPilha(PilhaSE *pilha) {
    pilha->topo = NULL;
}

int empilha(PilhaSE *pilha, Dado dado) {

    // Alocando memória para inserir um novo dado no nó
    Nodo *novoNodo = (Nodo *) malloc(sizeof(Nodo));

    if (novoNodo == NULL) return FALTOU_MEMORIA;

    novoNodo->info = dado;

    novoNodo->prox = pilha->topo;

    pilha->topo = novoNodo;

    return SUCESSO;
}

int desempilha(PilhaSE *pilha, Dado *dado) {

    if (pilha->topo == NULL) return PILHA_VAZIA;

    Nodo *aux = pilha->topo;

    *dado = aux->info;

    pilha->topo = aux->prox;

    free(aux);

    return SUCESSO;
}

int estaVazia(PilhaSE pilha) {

    if (pilha.topo == NULL) return PILHA_VAZIA;

    return SUCESSO;
}

int consultaTopo(PilhaSE pilha, Dado *dado) {
    if (pilha.topo == NULL) return PILHA_VAZIA;

    *dado = pilha.topo->info;
    
    return SUCESSO;
}

void exibe(PilhaSE pilha) {
    Nodo *aux = pilha.topo;

    if (aux == NULL) {
        printf("\nPilha vazia!\n");
    } 
    else {
        printf("\nNodos da pilha:\n");
        int i = 1;
        while (aux != NULL) {
            printf("Nodo: %d", i++);
            printf("\nCod: %d\nPeso: %.2f\n\n", aux->info.cod, aux->info.peso);
            aux = aux->prox;
        }
    }
}

int verificaCod(PilhaSE *pilha, int confereCod) {
    if (pilha->topo == NULL) return PILHA_VAZIA;

    Nodo *atual = pilha->topo;

    while (atual != NULL) {
        if (atual->info.cod == confereCod) {
            return COD_EXISTENTE;
        }
        atual = atual->prox;
    }

    return SUCESSO;
}

int contaNodos(PilhaSE *pilha) {
    int count = 0;
    Nodo *atual = pilha->topo;

    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }

    return count;
}   