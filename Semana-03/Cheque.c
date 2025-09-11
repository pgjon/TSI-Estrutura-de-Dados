
# include <stdio.h>
# include "Cheque.h"

void criaCheque(Cheque *c, int numeroCheque) { 
    c -> numero = numeroCheque;
    c -> situacao = 0;
    c -> valor = 0.0;
}

void exibeCheque(Cheque *exibeCheque) {
    printf("Número do Cheque: %d", exibeCheque->numero);
    printf("Situação do Cheque: %d", exibeCheque->situacao);
    printf("Valor do Cheque: %.2f", exibeCheque->valor);
}

int obtemSituacao(Cheque situacaoCheque) {
    return situacaoCheque.situacao;
}

float obtemValor(Cheque valorCheque) {
    return valorCheque.valor;
}

int obtemNumero(Cheque obtemNumeroCheque) {
    return obtemNumeroCheque.numero;
}

int compensaCheque(Cheque *compensaCheque) {
    /*
        compensaCheque
        Entrada/Saída: um cheque
        Retorno: Código 0 (sucesso), 1 (erro)
        Descrição: Altera a situação do cheque
        para 2(compensado). O cheque só pode ser
        compensado se a situação for igual a 1 (emitido)
    */

    if (compensaCheque->situacao == 1) {
        compensaCheque->situacao = 2;
        return 0;
    } else 
        return 1;
}

int emiteCheque(Cheque *cheque, float valorCheque) {
    /*
        emiteCheque
        Entrada/Saída: um cheque
        Entrada: Valor do cheque
        Retorno: Código 0 (sucesso), 1 (erro)
        Descrição: Atribui um valor ao cheque e altera 
        a situação para o código 1 (Emitido). O cheque só
        pode ser emitido se a situação for igual a 0 (em branco)
    */

    if (cheque->situacao == 0) {
        cheque->valor = valorCheque;
        cheque->situacao = 1;
        return 0;
    } else
        return 1;
}