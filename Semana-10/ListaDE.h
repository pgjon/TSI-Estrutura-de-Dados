#ifndef LISTADE_H
#define LISTADE_H

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
int consultaPorCodigo (ListaDE lista, Dado *dado, int cod);
int lerDadosValidos (ListaDE *lista, Dado *dado);

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

#endif