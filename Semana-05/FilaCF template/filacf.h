#ifndef filacf_h
#define filacf_h

#define SUCESSO    0
#define FILA_VAZIA 1
#define FILA_CHEIA 2
#define MAX_NODOS  5

typedef struct {
        int v[MAX_NODOS];
        int frente;
        int re;
        } FilaCF;

void criaFila(FilaCF *f);
int insere(FilaCF *f,int dado);
int retira(FilaCF *f,int *dado);
int estaCheia(FilaCF f);
int estaVazia(FilaCF f);
int consulta(FilaCF f,int *dado);
void exibeFila(FilaCF f);

#endif
