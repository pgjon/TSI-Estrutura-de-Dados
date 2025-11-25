#include "FilaSE.h"
#include <stdio.h>
#include <stdlib.h>

void criaFila(FilaSE *fila) {
  fila->frente = NULL;
  fila->re = NULL;
}

int estaVazia(FilaSE fila) {
  if (fila.frente == NULL && fila.re == NULL) {
    return FILA_VAZIA;
  }
  return SUCESSO;
}

int exibe(FilaSE fila) {
  if (estaVazia(fila)) {
    return FILA_VAZIA;
  }

  Nodo *aux = (Nodo *) malloc(sizeof(Nodo));
  aux = fila.frente;

  printf("\nFila:");
  printf("\n[Frente]\t[cod]\t\t[peso]\t\t[Ré]");

  while(aux != NULL) {
    printf("\n%p\t%d\t\t%.2f\t\t%p", aux, aux->info.cod, aux->info.peso, aux->prox);
    aux = aux->prox;
  }
  return SUCESSO;
}

int insere(FilaSE *fila, Dado dado) {
  Nodo *pNodo = (Nodo *) malloc(sizeof(Nodo));

  if (pNodo == NULL) {
    return FALTOU_MEMORIA;
  }

  pNodo->prox = NULL;
  pNodo->info = dado;

  if (estaVazia(*fila)) {
    fila->frente = pNodo;
  } else {
    fila->re->prox = pNodo;
  }

  fila->re = pNodo;
  return SUCESSO;
}

int retira(FilaSE *fila, Dado *dado) {
  if (estaVazia(*fila)) {
    return FILA_VAZIA;
  }

  Nodo *aux = fila->frente;
  *dado = aux->info;
  fila->frente = aux->prox;

  if (fila->frente == NULL) {
    fila->re = NULL;
  }

  free(aux);
  return SUCESSO;
}

int consulta(FilaSE fila, Dado *dado) {
  if (estaVazia(fila)) {
    return FILA_VAZIA;
  }

  *dado = fila.frente->info;
  return SUCESSO;
}

int confereCodigo(FilaSE fila, Dado *dado, int cod) {
  if (estaVazia(fila)) {
    return FILA_VAZIA;
  }

  Nodo *aux = fila.frente;

  while (aux != NULL) {
    if (aux->info.cod == cod) {
      *dado = aux->info;
      return SUCESSO;
    }
    aux = aux->prox;
  }

  return CODIGO_INEXISTENTE;
}

int quantidadeDeNodos(FilaSE fila) {
  if (estaVazia(fila)) {
    return 0;
  }

  Nodo *aux = fila.frente;
  int count = 0;

  while (aux != NULL) {
    count++;
    aux = aux->prox;
  }

  return count;
}