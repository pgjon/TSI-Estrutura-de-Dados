#include "ListaDE.h"
#include <stdio.h>
#include <stdlib.h>

// ######################### Funções iniciais ######################### 
void criaLista (ListaDE *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->n = 0;
}

int estaVazia (ListaDE lista) {
    if (lista.inicio == NULL && lista.fim == NULL && lista.n == 0) {
        return LISTA_VAZIA;
    }
    return SUCESSO;
}

int consultaPorCodigo (ListaDE lista, Dado *dado, int cod) {
    if (estaVazia(lista) == LISTA_VAZIA) {
        return LISTA_VAZIA;
    }

    Nodo *aux = lista.inicio;

    while(aux != NULL) {
        if (aux->info.cod == cod) {
            *dado = aux->info;
            return SUCESSO;
        }
        aux = aux->prox;
    }
        
    return CODIGO_INEXISTENTE;
}

int lerDadosValidos (ListaDE *lista, Dado *dado) {
    int resultado, cod;
    // repetição para conferir se existe código na lista
    do {
        printf("\nDigite o código a ser inserido: ");
        scanf("%d", &cod);

        resultado = consultaPorCodigo(*lista, dado, cod);

        if (resultado == CODIGO_INEXISTENTE || resultado == LISTA_VAZIA) {
            break;
        } else {
            printf("\nCódigo já existe na Lista!");
        }
    } while (1);
    
    dado->cod = cod;

    printf("Digite o peso: ");
    scanf("%f", &dado->peso);

    return SUCESSO;
}

// ######################### Fim Funções iniciais ######################### 

// ######################### Funções para incluir um Nodo ######################### 
int incluiNoInicio (ListaDE *lista, Dado dado) {
    Nodo *pNodo = (Nodo *) malloc (sizeof (Nodo));

    if (pNodo == NULL) {
        return FALTOU_MEMORIA;
    }

    pNodo->info = dado;
    pNodo->ant = NULL;
    pNodo->prox = lista->inicio;

    if (lista->n == 0) {
        lista->fim = pNodo;
    } else {
        lista->inicio->ant = pNodo;
    }

    lista->inicio = pNodo;
    lista->n++;
    return SUCESSO;
}

int incluiNoFim (ListaDE *lista, Dado dado) {
    Nodo *pNodo = (Nodo *) malloc (sizeof (Nodo));

    if (pNodo == NULL) {
        return FALTOU_MEMORIA;
    }

    pNodo->info=dado;
    pNodo->prox = NULL;
    pNodo->ant = lista->fim;

    if (lista->n == 0) {
        lista->inicio = pNodo;
    } else {
        lista->fim->prox = pNodo;
    }

    lista->fim = pNodo;
    lista->n++;
    return SUCESSO;
}

int incluiDepois (ListaDE *lista, Dado dado, int cod) {
    if (estaVazia(*lista) == LISTA_VAZIA) {
        return LISTA_VAZIA;
    }

    Nodo *aux = lista->inicio;
    // Percorre até o fim ou até encontrar o código
    while(aux != NULL && aux->info.cod != cod) {
        aux = aux->prox;
    }
    
    if (aux == NULL) { // Não encontrou o código
        return CODIGO_INEXISTENTE;
    }

    Nodo *pNodo = (Nodo *) malloc (sizeof (Nodo));

    if (pNodo == NULL) {
        return FALTOU_MEMORIA;
    }

    pNodo->info=dado;
    pNodo->ant = aux;
    pNodo->prox = aux->prox;

    if (aux->prox != NULL) {
        aux->prox->ant = pNodo;
    } else {
        // estava inserindo depois do último
        lista->fim = pNodo;
    }

    aux->prox = pNodo;
    lista->n++;
    return SUCESSO;

}
// ######################### Fim Funções para incluir um Nodo ######################### 

// ######################### Funções para excluir um Nodo ######################### 
int excluiNoInicio (ListaDE *lista, Dado *dado) {
    if (estaVazia(*lista) == LISTA_VAZIA) {
        return LISTA_VAZIA;
    }

    Nodo *pNodo;

    *dado = lista->inicio->info;
    pNodo = lista->inicio;
    lista->inicio = lista->inicio->prox;

    if (lista->n == 1) {
        lista->fim = NULL;
    } else {
        lista->inicio->ant = NULL;
    }

    lista->n--;
    free(pNodo);
    return SUCESSO;
}

int excluiNoFim (ListaDE *lista, Dado *dado) {
    if (estaVazia(*lista) == LISTA_VAZIA) {
        return LISTA_VAZIA;
    }

    Nodo *pNodo = lista->fim;
    *dado = lista->fim->info;

    if (lista->n == 1) {
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        lista->fim = lista->fim->ant;
        lista->fim->prox = NULL;
    }

    lista->n--;
    free(pNodo);
    return SUCESSO;
}

int excluiNodo (ListaDE *lista, Dado *dado, int cod) {
    if (estaVazia(*lista) == LISTA_VAZIA) {
        return LISTA_VAZIA;
    }

    Nodo *aux = lista->inicio;

    // 1) Procurar o nó com o código desejado
    while (aux != NULL && aux->info.cod != cod) {
        aux = aux->prox;
    }

    // Não encontrou
    if (aux == NULL) {
        return CODIGO_INEXISTENTE;
    }

    // 2) Guarda o dado antes de remover
    *dado = aux->info;

    // 3) Ajustar ponteiros conforme a posição do nó

    // Caso 1 → Nó é o primeiro
    if (aux->ant == NULL) {
        lista->inicio = aux->prox;
        // Verifica se a lista não ficou vazia após a remoção porque se aux->prox era único
        if (lista->inicio != NULL) {
            lista->inicio->ant = NULL;
        }
    }
    // Caso 2 → Nó é o último
    else if (aux->prox == NULL) {
        lista->fim = aux->ant;
        lista->fim->prox = NULL;
    }
    // Caso 3 → Nó está no meio
    else {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }

    // 4) Ajustar tamanho e liberar memória
    lista->n--;
    free(aux);

    // Caso a lista tenha ficado vazia após remover o único elemento
    if (lista->n == 0) {
        lista->inicio = NULL;
        lista->fim = NULL;
    }

    return SUCESSO;
}
// ######################### Fim Funções para excluir um Nodo ######################### 

// ######################### Funções exibe lista e sua situação ######################### 
void exibeLista(ListaDE lista) {
  Nodo *listaAux;

  listaAux = lista.inicio;

  printf("\nExibindo Lista:");

  // End = Endereço
  printf("\n[End. Nodo]\t[End. Ant]\t[Cod.]\t[Peso]\t[End. Prox.]");
  while (listaAux != NULL) {
    printf("\n%p\t%p\t%d\t%.2f\t%p", listaAux, listaAux->ant, listaAux->info.cod, listaAux->info.peso, listaAux->prox);
    listaAux = listaAux->prox;
  }
  printf("\n\nInicio: %p\tN: %d\tFim: %p", lista.inicio, lista.n, lista.fim);
}

void exibeSituacaoDaLista (ListaDE lista) {
    if (estaVazia(lista) == LISTA_VAZIA) {
        printf("\nLista Vazia!");
    } else {
        printf("\nA lista possui um ou mais Nodos.");
    }
}
// ######################### Fim Funções exibe lista e sua situação ######################### 

// ######################### Funções Ler e Gravar dados em arquivo de Texto ######################### 
void gravarArquivoTexto (char *nomeArquivo, ListaDE *lista) {
    FILE *arquivo = fopen(nomeArquivo, "w"); // abre o arquivo para escrita (sobrescreve)

    if (arquivo == NULL) { // verifica se abriu corretamente
        printf("\nNão foi possível abrir o arquivo!");
        return;
    } 

    Nodo *pNodo = lista->inicio;

    while (pNodo != NULL) { // percorre a lista inteira pelo número de nós
        // grava código e peso separados por espaço
        fprintf(arquivo, " %d %.2f\n", 
                pNodo->info.cod, 
                pNodo->info.peso);
        pNodo = pNodo->prox;
    }
    
    fclose(arquivo); // fecha o arquivo
    printf("\nDados gravados com SUCESSO!");
}

void lerArquivoTexto (char *nomeArquivo, ListaDE *lista) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("\nNão foi possível abrir o arquivo!");
        return;
    }

    criaLista(lista);  // limpa a lista antes de importar
    Dado dado;

    // lê até o final do arquivo
    while (fscanf(arquivo, "%d %f", &dado.cod, &dado.peso) != EOF) { // EOF = End of File - fazendo == 2 garante que cada linha lida está correta. 
        incluiNoFim(lista, dado);
    }

    fclose(arquivo);
    printf("\nImportação realizada com Sucesso!");
}
// ######################### Fim Funções Ler e Gravar dados em arquivo de Texto ######################### 