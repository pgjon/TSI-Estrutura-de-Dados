#ifndef ListaSE_H;
#define ListaSE_H
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
  struct nodo *prox;
} Nodo;

typedef struct {
  Nodo *inicio;
} ListaSE;

void criaLista(ListaSE *lista);
void exibe(ListaSE lista);
int estaVazia(ListaSE lista);

int incluiNoInicio(ListaSE *lista, Dado dado);
int incluiNoFim(ListaSE *lista, Dado dado);
int incluiDepois(ListaSE *lista, Dado dado, int cod);

int excluiDoInicio(ListaSE *lista, Dado *dado);
int excluiDoFim(ListaSE *lista, Dado *dado);
int excluiNodo(ListaSE *lista, Dado *dado, int cod);

int consultaPorCodigo(ListaSE *lista, Dado *dado, int cod);
int quantidadeDeNodos(ListaSE *lista);
#endif