#ifndef CHEQUE_H
#define CHEQUE_H

typedef struct {
    int numero;
    float valor;
    int situacao; 
} Cheque;

void criaCheque(Cheque *c, int numeroCheque);
void exibeCheque(Cheque *exibeCheque);
int obtemSituacao(Cheque situacaoCheque);
float obtemValor(Cheque valorCheque);
int obtemNumero(Cheque obtemNumeroCheque);
int compensaCheque(Cheque *compensaCheque);
int emiteCheque(Cheque *cheque, float valorCheque);

#endif 