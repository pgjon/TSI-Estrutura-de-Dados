#ifndef FilaCF_h
#define FilaCF_h

#define SUCESSO 0
#define FILA_VAZIA 1
#define FILA_CHEIA 2
#define DADO_INEXISTENTE 3
#define MAX_NODOS 5

// Estrutura do tipo dado
typedef struct {
    int cod;
    float peso;    
} Dado;
// Estrutura da fila
typedef struct {
    Dado v[MAX_NODOS];
    int frente, re;
} FilaCF;

void criaFila(FilaCF *fila); // procedimento para criar uma fila
int estaVazia(FilaCF fila); // função para verificar se a fila está vazia
int estaCheia(FilaCF fila); // função para verificar se a fila está cheia
int insere(FilaCF *fila, Dado dado); // função para inserir um dado na fila
int retira(FilaCF *fila, Dado *dado); // função para retirar dado da fila
int consulta(FilaCF fila, Dado *dado); // função para consultar o primeiro dado da fila
void exibe(FilaCF fila); // procedimento para mostrar a fila
int pesquisa(FilaCF *fila, int cod, Dado *dado); // função para consultar um dado atraves de um cod

#endif