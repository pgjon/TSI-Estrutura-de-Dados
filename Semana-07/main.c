/*

*/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "PilhaSE.h"

int main() {
  system("chcp 65001 > nul");
  setlocale(LC_ALL, "pt_BR.UTF-8");

  // Variables
  int opcao, flag, confereCod;
  PilhaSE pilha;
  Dado dado;
  // Inputs

  printf("\nLista exercício Pilha Simplesmente Encadeada!\n\n");
  printf("Menu de Opções:\n");

  criaPilha(&pilha);

  do {
    printf("\n0. Fim\t\t3. Quantidade de nodos");
    printf("\n1. Empilha\t4. Exibe situação da pilha");
    printf("\n2. Desempilha\t5. Consulta topo");

    printf("\n\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1: // Empilha
        printf("\nDigite o código do produto: ");
        scanf("%d", &confereCod);
        
        do {
            flag = verificaCod(&pilha, confereCod);
            if (flag == PILHA_VAZIA) {
                break;
            }
            else if (flag == COD_EXISTENTE) {
                printf("\nCódigo já existente na pilha!\nCódigo: ");
                scanf("%d", &confereCod);
            }
        } while (flag == COD_EXISTENTE);

        dado.cod = confereCod;
        printf("Digite o peso do produto: ");
        scanf("%f", &dado.peso);

        // Chama a função empilha para inserir o dado na pilha
        if (empilha(&pilha, dado) == SUCESSO) {
            printf("\nProduto empilhado com sucesso!\n");
        } else {
            printf("\nErro: Falta de memória!\n");
        }
        break;
    
    case 2: // Desempilha
        if (desempilha(&pilha, &dado) == PILHA_VAZIA) {
            printf("\nPilha vazia!\n");
        } else {
            printf("\nProduto desempilhado com sucesso!\n");
        }
        break;

    case 3: // Quantidade de nodos
        printf("\nQuantidade de nodos na pilha: %d\n", contaNodos(&pilha));
        break;

    case 4: // Exibe situação da pilha
        exibe(pilha);
        break;

    case 5: // Consulta topo
        if (consultaTopo(pilha, &dado) == PILHA_VAZIA) {
            printf("\nPilha vazia!\n");
        } else {
            printf("\nProduto no topo da pilha:\n");
            printf("Código: %d\n", dado.cod);
            printf("Peso: %.2f\n", dado.peso);
        }
        break;

    default: 
        printf("Opção inválida!\n");
        break;
    }
    printf("\n-------------------------------------------------------\n");
  } while (opcao != 0);
  // Outputs

  return 0;
}