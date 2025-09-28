/*
    
*/
# include <stdio.h>
# include <stdlib.h>
# include <locale.h>
# include "FilaCF.h"

int main(){
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Variables
    FilaCF fila;
    Dado dado;
    int opcao, cod, resultado;
    // Inputs
    criaFila(&fila);

    do {
        printf("Digite uma opção abaixo:\n");
        printf("\n0.Fim\t\t\t3.Quantidade de nodos\t\t6.Pesquisa dado");
        printf("\n1.Insere\t\t4.Exibe situação da fila");
        printf("\n2.Retira\t\t5.Consulta frente\nOpção: ");
        scanf("%d", &opcao);
    
        switch (opcao) {
            case 1: // Insere
                printf("Digite o código: ");
                scanf("%d", &dado.cod);

                printf("Digite o peso: ");
                scanf("%f", &dado.peso);

                resultado = insere(&fila, dado);

                if (resultado == SUCESSO)
                    printf("Inserido com sucesso!\n");
                else
                    printf("Falha: Fila está cheia!\n");
                break;

            case 2: // Retira
                resultado = retira(&fila, &dado);

                if (resultado == SUCESSO) {
                    printf("Retirado:\nCod: %d\nPeso: %.2f\n", dado.cod, dado.peso);
                }
                else {
                    printf("Falha: Fila está vazia!\n");
                }
                break;
            
            case 3: // Quantidade de nodos
                printf("Quantidade de nodos: %d\n", fila.re + 1);
                break;

            case 4: // Situação da fila
                exibe(fila);
                break;

            case 5: // Consulta frente
                resultado = consulta(fila, &dado);

                if (resultado == SUCESSO) {
                    printf("Frente da fila:\nCod: %d\nPeso: %.2f\n", dado.cod, dado.peso);
                }
                else {
                    printf("Falha: Fila está vazia!\n");
                }
                break;

            case 6: // Pesquisa código
                printf("Digite o código a ser pesquisado: ");
                scanf("%d", &cod);

                resultado = pesquisa(fila, cod, &dado);

                if (resultado == SUCESSO) {
                    printf("Dado encontrado:\nCod: %d\nPeso: %.2f\n", dado.cod, dado.peso);
                }
                else {
                    printf("Falha: Dado inexistente!\n");
                }
                break;
        }
    } while (opcao != 0);

    // Processing

    // Outputs

    return 0;
}