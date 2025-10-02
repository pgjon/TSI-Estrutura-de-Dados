#include "ListaCF.h"
#include <stdio.h>
#include <stdlib.h>

void criaLista(ListaCF *lista) { lista->n = 0; }

void exibeTracos() {
    int i;
    printf("\n");
    for (i = 1; i <= 75; i++) {
        printf("-");
    }
    printf("\n");
}

void exibe(ListaCF lista) {
    if (estaVazia(lista) == LISTA_VAZIA) {
        printf("\nLista Vazia!");
    }

    for (int i = 0; i < lista.n; i++) {
        printf("\nCódigo: %d", lista.v[i].cod);
        printf("\nPeso: %.2f\n", lista.v[i].peso);
    }
}

int estaVazia(ListaCF lista) {
    if (lista.n == 0) {
        return LISTA_VAZIA;
    }
    return SUCESSO;
}

int estaCheia(ListaCF lista) {
    if (lista.n == MAX_NODOS) {
        return LISTA_CHEIA;
    }
    return SUCESSO;
}

int incluiNoInicio(ListaCF *lista, Dado dado) {
    if (estaCheia(*lista) == LISTA_CHEIA) {
        return LISTA_CHEIA;
    }
    else {
        for (int i = lista->n; i >= 1; i--) {
            lista->v[i] = lista->v[i - 1];
        }
        lista->v[0] = dado;
        lista->n++;
        return SUCESSO;
    }
}

int incluiNoFim(ListaCF *lista, Dado dado) {
    if (estaCheia(*lista) == LISTA_CHEIA) {
        return LISTA_CHEIA;
    }
    else {
        lista->v[lista->n] = dado;
        lista->n++;
        return SUCESSO;
    }
}

int incluiAntes(ListaCF *lista, int cod, Dado dado) {
    if (estaCheia(*lista) == LISTA_CHEIA) {
        return LISTA_CHEIA;
    }
    for (int i = 0; i < lista->n; i++) {
        if (lista->v[i].cod == cod) {
            for (int j = lista->n; j > i - 1; j--) {
                lista->v[j] = lista->v[j - 1];
            }
            lista->v[i] = dado;
            lista->n++;
            return SUCESSO;
        }
    }
    return CODIGO_INEXISTENTE;
}

int excluiDoInicio(ListaCF *lista, Dado *dado) {
    if (estaVazia(*lista) == LISTA_VAZIA) {
        return LISTA_VAZIA;
    }

    *dado = lista->v[0];

    for (int i = 0; i < lista->n - 1; i++) {
        lista->v[i] = lista->v[i + 1];
    }
    lista->n--;
    printf("\nDado excluído com sucesso!\nCódigo: %d\nPeso: %.2f", dado->cod, dado->peso);
    return SUCESSO;
}

int excluiDoFim(ListaCF *lista, Dado *dado) {
    if (estaVazia(*lista) == LISTA_VAZIA) {
        return LISTA_VAZIA;
    }

    *dado = lista->v[lista->n - 1];
    lista->n--;
    printf("\nDado excluído com sucesso!\nCódigo: %d\nPeso: %.2f", dado->cod, dado->peso);
    return SUCESSO;
}

int excluiNodo(ListaCF *lista, int cod, Dado *dado) {
    if (estaVazia(*lista) == LISTA_VAZIA) {
        return LISTA_VAZIA;
    }

    for (int i = 0; i < lista->n; i++) {
        if (lista->v[i].cod == cod) {
            *dado = lista->v[i];
            for (int j = i; j < lista->n; j++) {
                lista->v[j] = lista->v[j + 1];
            }
            lista->n--;
            printf("\nNodo excluido com sucesso!\nCódigo: %d\nPeso: %.2f", dado->cod, dado->peso);
            return SUCESSO;
        }
    }
    return CODIGO_INEXISTENTE;
}

int quantidadeDeNodos(ListaCF lista) {
    return (lista.n);
}

int consultarPorCodigo(ListaCF lista, int cod, Dado *dado) {
    if (estaVazia(lista) == LISTA_VAZIA) {
        return LISTA_VAZIA;
    }
    for (int i = 0; i < lista.n; i++) {
        if (lista.v[i].cod == cod) {
            *dado = lista.v[i];
            printf("\nNodo econtrado com sucesso!\nCódigo: %d\nPeso: %.2f", dado->cod, dado->peso);
            return SUCESSO;
        }
    }
    return CODIGO_INEXISTENTE;
}

int confereCod(ListaCF lista, int cod) {
    // função para conferir se o código digitado na main.c já existe na lista
    for (int i = 0; i < lista.n; i++) {
        if (lista.v[i].cod == cod) {
            return CODIGO_EXISTENTE;
        }
    }
    return SUCESSO;
}

