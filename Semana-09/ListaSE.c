#include "ListaSE.h"
#include <stdio.h>

void criaLista(ListaSE *lista) { lista->inicio = NULL; }

void exibe(ListaSE lista) {
  Nodo *listaAux;

  listaAux = lista.inicio;

  printf("\nInicio: %p", lista.inicio);
  printf("\nExibindo Lista:");
  printf("\n[EndNodo]\t[cod]\t[peso]\t[EndProx]");
  while (listaAux != NULL) {
    printf("\n%p\t%3d\t%.2f\t%p", listaAux, listaAux->info.cod,
           listaAux->info.peso, listaAux->prox);
    listaAux = listaAux->prox;
  }
}

int estaVazia(ListaSE lista) {
  if (lista.inicio == NULL)
    return LISTA_VAZIA;
  else
    return SUCESSO;
}

int incluiNoInicio(ListaSE *lista, Dado dado) {
  Nodo *proxNodo;

  proxNodo = (Nodo *)malloc(sizeof(Nodo));

  if (proxNodo == NULL)
    return FALTOU_MEMORIA;

  else {
    proxNodo->info = dado;
    proxNodo->prox = lista->inicio;
    lista->inicio = proxNodo;
    return SUCESSO;
  }
}

int incluiNoFim(ListaSE *lista, Dado dado) {
  Nodo *proxNodo = (Nodo *)malloc(sizeof(Nodo));
  if (proxNodo == NULL)
    return FALTOU_MEMORIA;

  proxNodo->info = dado;
  proxNodo->prox = NULL;

  // lista vazia: novo nodo se torna o início
  if (lista->inicio == NULL) {
    lista->inicio = proxNodo;
    return SUCESSO;
  }

  // percorre sem modificar lista->inicio
  Nodo *aux = lista->inicio;
  while (aux->prox != NULL) {
    aux = aux->prox;
  }
  aux->prox = proxNodo;
  return SUCESSO;
}

int incluiDepois(ListaSE *lista, Dado dado, int cod) {

  Nodo *aux = lista->inicio;
  while (aux != NULL && aux->info.cod != cod) {
    aux = aux->prox;
  }

  if (aux == NULL)
    return CODIGO_INEXISTENTE;

  Nodo *proxNodo = (Nodo *)malloc(sizeof(Nodo));
  if (proxNodo == NULL)
    return FALTOU_MEMORIA;

  proxNodo->info = dado;
  proxNodo->prox = aux->prox;
  aux->prox = proxNodo;

  return SUCESSO;
}

int excluiDoInicio(ListaSE *lista, Dado *dado) {
  if (lista->inicio == NULL)
    return LISTA_VAZIA;

  Nodo *aux = lista->inicio;
  *dado = aux->info;
  lista->inicio = aux->prox;
  free(aux);
  return SUCESSO;
}

int excluiDoFim(ListaSE *lista, Dado *dado) {
  if (lista->inicio == NULL)
    return LISTA_VAZIA;

  Nodo *atual = lista->inicio;
  Nodo *anterior = NULL;

  while (atual->prox != NULL) {
    anterior = atual;
    atual = atual->prox;
  }

  *dado = atual->info;

  if (anterior == NULL) {
    lista->inicio = NULL;
  } else {
    anterior->prox = NULL;
  }

  free(atual);
  return SUCESSO;
}

int excluiNodo(ListaSE *lista, Dado *dado, int cod) {
  if (lista->inicio == NULL)
    return LISTA_VAZIA;

  Nodo *atual = lista->inicio;
  Nodo *anterior = NULL;

  while (atual != NULL && atual->info.cod != cod) {
    anterior = atual;
    atual = atual->prox;
  }

  if (atual == NULL)
    return CODIGO_INEXISTENTE;

  *dado = atual->info;

  if (anterior == NULL) {
    lista->inicio = atual->prox;
  } else {
    anterior->prox = atual->prox;
  }

  free(atual);
  return SUCESSO;
}

int consultaPorCodigo(ListaSE *lista, Dado *dado, int cod) {
  if (lista->inicio == NULL)
    return LISTA_VAZIA;

  Nodo *atual = lista->inicio;
  while (atual != NULL) {
    if (atual->info.cod == cod) {
      *dado = atual->info;
      return SUCESSO;
    }
    atual = atual->prox;
  }
  return CODIGO_INEXISTENTE;
}

int quantidadeDeNodos(ListaSE *lista) {
  if (lista->inicio == NULL)
    return 0;

  int qtd = 0;
  Nodo *percorre = lista->inicio;

  while (percorre != NULL) {
    qtd++;
    percorre = percorre->prox;
  }
  return qtd;
}