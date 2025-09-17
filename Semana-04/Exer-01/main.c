/*
    
*/
# include <stdio.h>
# include <locale.h>
# include <stdlib.h>
# include "pilhacf.h"

int main(){
    //system("clear");
    system("chcp 65001 > nul"); // altera a página de código para UTF-8 e esconde a mensagem do Windows
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    // Variables
    PilhaCF pilha;
    Dado dado;
    int opcao, cod, resultado;

    criaPilha(&pilha);

    // Inputs
    do {
        printf("Digite uma opção abaixo:\n");
        printf("\n0.Fim\t\t\t3.Quantidade de nodos\t\t6.Pesquisa código");
        printf("\n1.Empilha\t\t4.Exibe situação da pilha");
        printf("\n2.Desempilha\t\t5.Consulta topo\nOpção: ");
        scanf("%d", &opcao);
    
        switch (opcao) {
            case 1: // Empilha
                printf("Digite o código: ");
                scanf("%d", &dado.cod);

                printf("Digite o peso: ");
                scanf("%f", &dado.peso);

                resultado = empilha(&pilha, dado);

                if (resultado == SUCESSO)
                    printf("Empilhado com sucesso!\n");
                else
                    printf("Falha: Pilha está cheia!\n");
                break;

            case 2: // Desempilha
                resultado = desempilha(&pilha, &dado);

                if (resultado == SUCESSO) {
                    printf("Desempilhado:\nCod: %d\nPeso: %.2f\n", dado.cod, dado.peso);
                }
                else {
                    printf("Falha: Pilha está vazia!\n");
                }
                break;
            
            case 3: // Quantidade de nodos
                printf("Quantidade de nodos: %d\n", pilha.topo + 1);
                break;

            case 4: // Situação da pilha
                if (pilha.topo == -1)
                    printf("A pilha está vazia!\n");
                else if (pilha.topo == MAX_NODOS - 1)
                    printf("A pilha está cheia!\n");
                else
                    printf("A pilha possue 1 ou mais nodos!\n");
                break;
            
            case 5: // Consulta topo
                resultado = consultaTopo(&pilha, &dado);

                if (resultado == SUCESSO) 
                    printf("Topo da pilha:\nCod: %d\nPeso: %.2f\n", dado.cod, dado.peso);
                else
                    printf("Falha: Pilha vazia!\n");
                break;
            case 6: // Pesquisa
                printf("Digite o código para pesquisar: ");
                scanf("%d", &cod);

                resultado = pesquisa(&pilha, cod, &dado);

                if (resultado == SUCESSO)
                    printf("Encontrado:\nCod: %d\nPeso: %.2f\n", dado.cod, dado.peso);
                else
                    printf("Código não encontrado!\n");
                break;
            
            case 0: // Encerra o programa
                printf("Encerrando o programa...\n");
                break;
            
            default:
                printf("Opção inválida!\n");
        }

        // Exibindo informação após operação do switch case
        printf("\nEstado atual da pilha:\n");
        exibe (&pilha);

    } while (opcao != 0);
    // Processing

    // Outputs

    return 0;
}