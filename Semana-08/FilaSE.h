#ifndef FilaSE_H
#define FilaSE_H
# define SUCESSO 0
# define FILA_VAZIA 1
# define FALTOU_MEMORIA 2
# define CODIGO_INEXISTENTE 3

typedef struct {
  int cod;
  float peso;
} Dado;

typedef struct nodo {
  Dado info;
  struct nodo *prox;
} Nodo;

typedef struct {
  Nodo *frente, *re;
} FilaSE;

void criaFila(FilaSE *fila);
int estaVazia(FilaSE fila);
int exibe(FilaSE fila);
int insere(FilaSE *fila, Dado dado);
int retira(FilaSE *fila, Dado *dado);
int consulta(FilaSE fila, Dado *dado);
int confereCodigo(FilaSE fila, Dado *dado, int cod);
int quantidadeDeNodos(FilaSE fila);
#endif