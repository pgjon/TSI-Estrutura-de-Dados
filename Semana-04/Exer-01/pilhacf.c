
# include <stdio.h>
# include <stdlib.h>
# include "pilhacf.h"

// Criando uma pilha vazia
void criaPilha(PilhaCF *pilha) {
    pilha->topo = -1;
}

// Empilhando um elemento na pilha
int empilha(PilhaCF *pilha, Dado d) {
    // condição que verifica se o topo da pilha está preenchido
    if (pilha->topo == MAX_NODOS - 1) {
        return PILHA_CHEIA;
    } 
    else {
        /*  
            caso a condição anterior seje falsa, 
            ele incrementa a variável topo, ou seja
            adiciona mais um índice para receber um dado
            na pilha
        */
        pilha->topo++;

        /*
            após incrementar mais um índice na pilha,
            ele coloca o dado passado como parametro para a função
            no índice que a pilha está no momento.
        */
        pilha->v[pilha->topo] = d;

        return SUCESSO;
    }
}

// Retirando elemento da pilha
int desempilha (PilhaCF *pilha, Dado *d) {
    // condição que verifica se a pilha está vazia
    if (pilha->topo == -1) {
        return PILHA_VAZIA;
    }
    else {
        /*
            caso a pilha não esteja vazia abaixo
            o endereço de *d recebe o valor do indice da pilha
        */
        *d = pilha->v[pilha->topo];

        // após, decrementa o topo, ou seja, tira da pilha o valor
        // que está no índice
        pilha->topo--;
        return SUCESSO;
    }
}

// Verificando se está vazia
int estaVazia (PilhaCF *pilha) {
    if (pilha->topo == -1)
        return PILHA_VAZIA;
    return SUCESSO;
}

// Consulta o elemento no topo sem remover
int consultaTopo (PilhaCF *pilha, Dado *d) {
    if (pilha->topo == -1) 
        return PILHA_VAZIA;
    else {
        *d = pilha->v[pilha->topo];
        return SUCESSO;
    }
}

// Exibe elementos da pilha (do topo até a base)
void exibe (PilhaCF *pilha) {
    int i;

    if (pilha->topo == -1)
        printf("Pilha Vazia!\n");
    else {
        printf ("Pilha (Topo para Base):\n");

        for (i = pilha->topo; i >= 0; i--) {
            printf("Cod: %d\nPeso: %.2f\n", pilha->v[i].cod, pilha->v[i].peso);
        }
    }
}

// Pesquisa um elemento pelo código
int pesquisa (PilhaCF *pilha, int cod, Dado *d) {
    int i;

    for (i = pilha->topo; i >= 0; i--) {
        if (pilha->v[i].cod == cod) {
            *d = pilha->v[i];
            return SUCESSO;
        }
    }
    return DADO_INEXISTENTE;
}

