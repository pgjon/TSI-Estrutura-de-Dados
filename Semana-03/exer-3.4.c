/*
    3.4 Defina o tipo Cheque para armazenar o número, o valor e a situação (0-Em branco, 1-Emitido, 2-Compensado) de um cheque.
    
    Implemente as seguintes operações:
    Inclua as definições e protótipos no arquivo Cheque.h
    A implementação das funções no arquivo Cheque.c
    
    criaCheque                                         exibeCheque
    Saída: um cheque                                   Entrada: Um cheque
    Entrada: Número do cheque                          Descrição: Exibe um uma única linha
    Descrição: Atribui os valores iniciais.            as 3 informações contidas no cheque.
    O valor e a situação do cheque devem ser zerados.
    
    obtemSituacao                                      obtemValor
    Entrada: um cheque                                 Entrada: um cheque
    Retorno: O código da situação do cheque            Retorno: O valor do cheque
    
    obtemNumero                                        compensaCheque
    Entrada: um cheque                                 Entrada/Saída: um cheque
    Retorno: O número do cheque                        Retorno: Código 0 (sucesso), 1 (erro)
                                                       Descrição: Altera a situação do cheque
                                                       para 2(compensado). O cheque só pode ser
                                                       compensado se a situação for igual a 1 (emitido)

    emiteCheque
    Entrada/Saída: um cheque
    Entrada: Valor do cheque
    Retorno: Código 0 (sucesso), 1 (erro)
    Descrição: Atribui um valor ao cheque e altera 
    a situação para o código 1 (Emitido). O cheque só
    pode ser emitido se a situação for igual a 0 (em branco)
    
    Escreva um programa para ler dois números e criar dois cheques armazenando-os em 2 variáveis (usar criaCheque).
    Ler 2 valores e emitir os 2 cheques (usar emiteCheque).
    Escrever na tela os dados dos 2 cheques (usar exibeCheque).
    Compensar o que possui maior valor (usar obtemValor para obter o valor de cada cheque e compensaCheque para fazer a compensação.
    Escreva somente o código da situação dos 2 cheques (usar obtemSituacao).
    Escreva somente o número dos 2 cheques (usar obtemNumero).
*/
# include <stdio.h>
# include <locale.h>
# include "Cheque.h"

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Variables
    int numCheque_1, numCheque_2;
    Cheque Cheque_1, Cheque_2;
    
    // Inputs
    printf("Digite o número do primeiro Cheque: ");
    scanf("%d", &numCheque_1);

    printf("Digite o número do segundo Cheque: ");
    scanf("%d", &numCheque_2);

    // Criando os dois cheques - Parte 1
    criaCheque(&Cheque_1, numCheque_1);
    criaCheque(&Cheque_2, numCheque_2);

    // Declarando variáveis para os valores dos cheques
    float Valor_1, Valor_2;
    printf("Digite valor do primeiro Cheque: ");
    scanf("%d", &Valor_1);

    printf("Digite valor do segundo Cheque: ");
    scanf("%d", &Valor_2);

    // Emitindo cheques - Parte 2
    emiteCheque(&Cheque_1, Valor_1);
    emiteCheque(&Cheque_2, Valor_2);

    // Exibindo os Cheques - Parte 3
    printf("\nDados dos Cheques!\n");
    exibeCheque(&Cheque_1);
    exibeCheque(&Cheque_2);

    // Variáveis para obter os valores dos cheques
    float valorCheque_1, valorCheque_2;

    // Obtendo os valores - Parte 4
    valorCheque_1 = obtemValor(Cheque_1);
    valorCheque_2 = obtemValor(Cheque_2);

    // Compensando os cheques - Parte 5
    if ((valorCheque_1 > valorCheque_2) || (valorCheque_1 == valorCheque_2)) {
        compensaCheque(&Cheque_1);
        if (valorCheque_1 == valorCheque_2) 
            printf("\nCheque 1 compensado (valores iguais)\n");
        else 
            printf("\nCheque 1 compensado (maior valor)\n");
    } else {
        compensaCheque(&Cheque_2);
        printf("\nCheque 2 compensado (maior valor)\n");
    }

    // Obtendo situação dos cheques - Parte 6
    printf("\nSituações dos cheques:\n");
    printf("Cheque 1: %d\n", obtemSituacao(Cheque_1));
    printf("Cheque 2: %d\n", obtemSituacao(Cheque_2));

    // Mostrando os números dos cheques - Parte 7
    printf("\nNúmeros dos cheques:\n");
    printf("Cheque 1: %d\n", obtemNumero(Cheque_1));
    printf("Cheque 2: %d\n", obtemNumero(Cheque_2));
    
    return 0;
}