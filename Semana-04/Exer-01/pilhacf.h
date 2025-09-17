# ifndef Pilhacf_h
# define Pilhacf_h

# define SUCESSO 0
# define PILHA_VAZIA 1
# define PILHA_CHEIA 2
# define DADO_INEXISTENTE 3
# define MAX_NODOS 5

typedef struct {
    int cod;
    float peso;
} Dado;

typedef struct {
    Dado v[MAX_NODOS];
    int topo;
} PilhaCF;


// Protótipos das funções
void criaPilha (PilhaCF *pilha);
int empilha (PilhaCF *pilha, Dado d);
int desempilha (PilhaCF *pilha, Dado *d);
int estaVazia (PilhaCF *pilha);
int consultaTopo (PilhaCF *pilha, Dado *d);
void exibe (PilhaCF *pilha);
int pesquisa (PilhaCF *pilha, int cod, Dado *d);

# endif