#include <stdio.h>
#include <stdlib.h>
#include "listase.h"

void criaLista(ListaSE *lt){
     lt->inicio = NULL;
}

int incluiNoInicio(ListaSE *lt, Dado d){
    Nodo *pNodo;
    pNodo = (Nodo *) malloc (sizeof (Nodo));
    if (pNodo == NULL)
       return(FALTOU_MEMORIA);
    else {
       pNodo->info = d;
       pNodo->prox = lt->inicio;
       lt->inicio = pNodo;
       return(SUCESSO);
    }
}
 
void exibe(ListaSE lt){
     Nodo *pAux;
     pAux = lt.inicio;
     printf("\nInicio: %p \n", lt.inicio);
     printf("Exibindo a Lista\n");
     printf("[EndNodo] [cd] [peso] [EndProx]\n");
     while (pAux != NULL) {
           printf("%p - %3d %.2f - %p\n", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);
           pAux = pAux->prox;
     }
}

int quantidadeDeNodos(ListaSE lt){
    int conta=0;
    Nodo *pAux;
    
    pAux = lt.inicio;
    while (pAux != NULL) {
           conta++;
           pAux = pAux->prox;
    }
    return(conta);
}

int estaVazia(ListaSE lt){
    if (lt.inicio==NULL)
       return(LISTA_VAZIA);
    else
       return(0);     
}

