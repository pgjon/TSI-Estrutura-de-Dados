#include <stdio.h>
#include <stdlib.h>
#include "FilaCF.h"

// exibe tracos
void exibeTracos() {
    int i;
    for (i = 1; i <= 75; i++) {
        printf("-");
    }
    printf("\n");
}

// procedimento para criar uma fila
void criaFila(FilaCF *fila) {
    fila->frente = 0;
    fila->re = 0;
}

// função para verificar se a fila está vazia
int estaVazia(FilaCF fila) {
    return (fila.frente == fila.re);
}

// função para verificar se a fila está cheia
int estaCheia(FilaCF fila) {
    /* A fila está cheia quando o próximo índice de re for igual ao índice de frente
        Exemplo: MAX_NODOS = 5
        fila.re = 4 (último índice ocupado)
        fila.frente = 0 (primeiro índice ocupado)
        Próximo índice de re = (4 + 1) % 5 = 0
        Como o próximo índice de re é igual ao índice de frente, a fila está cheia
    */
    return ((fila.re + 1) % MAX_NODOS == fila.frente);
}

// função para inserir um dado na fila
int insere(FilaCF *fila, Dado dado) {
    // Verifica primeiro se a fila ta cheia
    if (estaCheia(*fila)) { 
        return FILA_CHEIA; 
    }
    // caso a fila esteja com espaço
    fila->v[fila->re] = dado; // insere o dado no índice re da fila
    fila->re = (fila->re + 1) % MAX_NODOS; // atualiza o índice re para o próximo índice circularmente
    return SUCESSO;
}

// função para retirar dado da fila
int retira(FilaCF *fila, Dado *dado) {
    // Verifica se a fila está vazia
    if (estaVazia(*fila)) {
        return FILA_VAZIA;
    }
    *dado = fila->v[fila->frente]; /* o endereço de dado recebe o valor do índice da frente da fila
                                       após, incrementa a frente, ou seja, tira da fila o valor que está no índice */
    fila->frente = (fila->frente + 1) % MAX_NODOS; // atualiza o índice frente para o próximo índice 
                                                   // circularmente
    return SUCESSO;
}

// função para consultar o primeiro dado da fila
int consulta(FilaCF fila, Dado *dado) {
    // verifica se a fila está vazia
    if (estaVazia(fila)) {
        return FILA_VAZIA;
    }
    // caso não esteja vazia, o endereço de dado recebe o valor do índice da frente da fila
    *dado = fila.v[fila.frente]; // mostra o valor que está no índice da frente
    return SUCESSO;
}

// procedimento para mostrar a fila
void exibe(FilaCF fila) {
    // verifica se a fila está vazia
    if (estaVazia(fila)) {
        printf("\nFila vazia!\n");
        return; // sai do procedimento
    }
    else if (fila.frente - MAX_NODOS == fila.re || fila.re + 1 == fila.frente) {
        printf("\nA fila está cheia!\n");
    }
    else {
        printf("\nA fila possui um ou mais nodos!\n");
    }
    printf("\nFila: \n");
    // percorre a fila do índice frente até o índice re
    for (int i = fila.frente; i != fila.re; i = (i + 1) % MAX_NODOS) {
        printf("Cod: %d\nPeso: %.2f\n\n", fila.v[i].cod, fila.v[i].peso);
    }
}

// função para pesquisar um código existente na fila, sem remover do nodo
int pesquisaValida(FilaCF fila, int cod) {
    /*
        pesquisa de forma circular para saber se o cod inserido no main existe na fila
    */
    int i = fila.frente;
    while (i != fila.re) {
        if (fila.v[i].cod == cod) {
            return SUCESSO;
        }
        i = (i + 1) % MAX_NODOS;
    }
    return DADO_INEXISTENTE;
}
    
// função para consultar um dado atraves de um cod
int pesquisa(FilaCF *fila, int cod, Dado *dado) {
    // verifica se a fila está vazia
    if (estaVazia(*fila)) {
        return FILA_VAZIA;
    }
    // percorre a fila em busca do código
    Dado aux;
    int QtdDadosFila = (fila->re - fila->frente + MAX_NODOS) % MAX_NODOS; // Quantidade de dados existente na 
                                                                          // fila
    
    for (int i = 0; i < QtdDadosFila; i++) {
        retira(fila, &aux);
        if (aux.cod == cod) {
            *dado = aux;
            return SUCESSO;
        }
    }
    return DADO_INEXISTENTE;
}