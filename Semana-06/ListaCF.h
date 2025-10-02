#ifndef ListaCF_h
#define ListaCF_h

#define SUCESSO 0
#define LISTA_VAZIA 1
#define LISTA_CHEIA 2
#define CODIGO_INEXISTENTE 3
#define CODIGO_EXISTENTE 4
#define MAX_NODOS 5

typedef struct {
    int cod;
    float peso;
} Dado;

typedef struct {
    int n;
    Dado v[MAX_NODOS];
} ListaCF;

void criaLista(ListaCF *lista);
void exibeTracos();
void exibe(ListaCF lista);

int estaVazia(ListaCF lista);
int estaCheia(ListaCF lista);

int incluiNoInicio(ListaCF *lista, Dado dado);
int incluiNoFim(ListaCF *lista, Dado dado);
int incluiAntes(ListaCF *lista, int cod, Dado dado);

int excluiDoInicio(ListaCF *lista, Dado *dado);
int excluiDoFim(ListaCF *lista, Dado *dado);
int excluiNodo(ListaCF *lista, int cod, Dado *dado);

int quantidadeDeNodos(ListaCF lista);
int consultarPorCodigo(ListaCF lista, int cod, Dado *dado);

int confereCod(ListaCF lista, int cod);
#endif

