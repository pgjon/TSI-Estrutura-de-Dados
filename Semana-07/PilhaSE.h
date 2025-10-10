#ifndef PilhaSE_h
#define PilhaSE_h

#define SUCESSO 0
#define PILHA_VAZIA 1
#define FALTOU_MEMORIA 2
#define COD_EXISTENTE 3

typedef struct {
    int cod;
    float peso;
} Dado;

typedef struct nodo {
    Dado info;
    struct nodo *prox;
} Nodo;

typedef struct {
    Nodo *topo;
} PilhaSE;

void criaPilha(PilhaSE *pilha);
int empilha(PilhaSE *pilha, Dado dado);
int desempilha(PilhaSE *pilha, Dado *dado);
int estaVazia(PilhaSE pilha);
int consultaTopo(PilhaSE pilha, Dado *dado);
void exibe(PilhaSE pilha);

int verificaCod(PilhaSE *pilha, int confereCod);
int contaNodos(PilhaSE *pilha);

#endif