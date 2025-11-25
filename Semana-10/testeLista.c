#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct {
    int cod;
    float peso;
} Dado;

typedef struct nodo {
    Dado info;
    struct nodo *prox, *ant;
} Nodo;

typedef struct {
    Nodo *inicio;
    Nodo *fim;
    int n;
} ListaDE;

// Funções iniciais
void criaLista (ListaDE *lista);
int estaVazia (ListaDE lista);
int consultaPorCodigo (ListaDE lista, int cod);

// Funções para incluir um Nodo
int incluiNoInicio (ListaDE *lista, Dado dado);
int incluiNoFim (ListaDE *lista, Dado dado);
int incluiDepois (ListaDE *lista, Dado dado, int cod);

// Funções para excluir um Nodo
int excluiNoInicio (ListaDE *lista, Dado *dado);
int excluiNoFim (ListaDE *lista, Dado *dado);
int excluiNodo (ListaDE *lista, Dado *dado, int cod);

// Funções Exibe Lista
void exibeLista (ListaDE lista);
void exibeSituacaoDaLista (ListaDE lista);

// Funções ler e gravar dados em arquivo de texto
void gravarArquivoTexto (char *nomeArquivo, ListaDE *lista);
void lerArquivoTexto (char *nomeArquivo, ListaDE *lista);






// ########################## MAIN ##########################
int main () {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int opcao, cod, resultado;
    ListaDE lista;
    Dado dado;

    criaLista(&lista);

    printf("\nLista Duplamente Encadeada\nBy: Jones Rodrigues\n");

    do {
        printf("\n################################# MENU DE OPÇÕES #################################");
        printf("\n _________________________________________________________________________________");
        printf("\n|                                                                                 |");
        printf("\n|0. Fim                 5. Exclui do Inicio         10. Consulta por Código       |");    
        printf("\n|1. Inclui no Inicio    6. Exclui do Fim            11. Gravar em Arquivo de Texto|");    
        printf("\n|2. Inclui no Fim       7. Exclui Nodo              12. Ler de Arquivo de Texto   |");    
        printf("\n|3. Inclui Depois       8. Quantidade de Nodos                                    |");    
        printf("\n|4. Exibe Lista         9. Exibe Situação da Lista                                |");
        printf("\n|_________________________________________________________________________________|");
        printf("\n\nOpção: ");    
        scanf("%d", &opcao);

        switch (opcao) {
        case 1: // Inclui no Inicio
            
            break;
        
        case 2: // Inclui no Fim
            
            break;
        
        case 3: // Inclui Depois
            
            break;
        
        case 4: // Exibe Lista
            
            break;
        
        case 5: // Exclui do Inicio
            
            break;
        
        case 6: // Exclui do Fim
            
            break;
        
        case 7: // Exclui Nodo
            
            break;
        
        case 8: // Quantidade de Nodos
            
            break;
        
        case 9: // Exibe Situação da Lista
            
            break;
        
        case 10: // Consulta por Código
            
            break;
        
        case 11: // Gravar em Arquivo de Texto
            
            break;
        
        case 12: // Ler de Arquivo de Texto
            
            break;
        
        default: // Opção inválida
            printf("\nOpção inválida!");
            break;
        }
    } while (opcao != 0);

    return 0;
}













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

int consultaPorCodigo (ListaDE lista, int cod) {
    if (estaVazia(lista) == LISTA_VAZIA) {
        return LISTA_VAZIA;
    }

    Nodo *aux = lista.inicio;

    while(aux != NULL && aux->info.cod != cod) {
        aux = aux->prox;
    }
    
    if (aux == NULL) {
        return CODIGO_INEXISTENTE;
    }

    printf("\nCod: %d\nPeso: %.2f", aux->info.cod, aux->info.peso);
    return SUCESSO;
}
// ######################### Fim Funções iniciais ######################### 

// ######################### Funções para incluir um Nodo ######################### 
int incluiNoInicio (ListaDE *lista, Dado dado) {
    Nodo *pNodo;

    pNodo = (Nodo *) malloc (sizeof (Nodo));

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
    Nodo *pNodo;

    pNodo = (Nodo *) malloc (sizeof (Nodo));

    if (pNodo == NULL) {
        return FALTOU_MEMORIA;
    }

    pNodo->info=dado;
    pNodo->prox = NULL;
    pNodo->ant = lista->fim;

    if (lista->n == 0) {
        lista->inicio = pNodo;
    } else {
        lista->fim->ant = pNodo;
    }

    lista->fim = pNodo;
    lista->n++;
    return SUCESSO;
}

int incluiDepois (ListaDE *lista, Dado dado, int cod) {
    Nodo *aux = lista->inicio;
    while(aux->prox != NULL && aux->info.cod != cod) {
        aux = aux->prox;
    }
    
    if (aux == NULL) {
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

    Nodo *pNodo;

    *dado = lista->fim->info;
    pNodo = lista->fim;
    lista->fim = lista->fim->ant;

    if (lista->n == 1) {
        lista->inicio = NULL;
    } else {
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
void exibe(ListaDE lista) {
  Nodo *listaAux;

  listaAux = lista.inicio;

  printf("\nInicio: %p", lista.inicio);
  printf("\nExibindo Lista:");
  printf("\nInicio: %p", lista.inicio);
  // End = Endereço
  printf("\n[End. Nodo]\t[End. Ant]\t[Cod.]\t[Peso]\t[End. Prox.]");
  while (listaAux != NULL) {
    printf("\n%p %p %d %.2f %p", listaAux, listaAux->ant, listaAux->info.cod, listaAux->info.peso, listaAux->prox);
    listaAux = listaAux->prox;
  }
  printf("\nQuantidade de Nodos - N: %d\nFim: %p", lista.n, lista.fim);
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
    FILE *arquivo;
    Nodo *pNodo;

    arquivo = fopen(nomeArquivo, "w"); // abre o arquivo para escrita (sobrescreve)

    if (arquivo == NULL) { // verifica se abriu corretamente
        printf("\nNão foi possível abrir o arquivo!");
        return;
    } 
    pNodo = lista->inicio;

    for (int i = 0; i < lista->n; i++) { // percorre a lista inteira pelo número de nós
        fprintf(arquivo,    // grava código e peso separados por espaço
                "\n%d %.2f", 
                pNodo->info.cod, 
                pNodo->info.peso
        );

        pNodo = pNodo->prox;
    }
    
    fclose(arquivo); // fecha o arquivo
    printf("\nDados gravados com SUCESSO!");
}

void lerArquivoTexto (char *nomeArquivo, ListaDE *lista) {
    FILE *arquivo;
    Dado dado;
    
    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("\nNão foi possível abrir o arquivo!");
        return;
    }

    criaLista(lista);  // limpa a lista antes de importar

    while (fscanf(arquivo, "%d %.2f", &dado.cod, &dado.peso) == EOF) { // EOF = End of File - fazendo == 2 garante que cada linha lida está correta. 
        incluiNoFim(lista, dado);
    }

    fclose(arquivo);
    printf("\nImportação realizada com Sucesso!");
}
// ######################### Fim Funções Ler e Gravar dados em arquivo de Texto ######################### 