#include "FilaSE.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  system("chcp 65001 > nul");
  setlocale(LC_ALL, "pt_BR.UTF-8");

  int opcao, cod, resultado;
  FilaSE fila;
  Dado dado;

  criaFila(&fila);

  do {
    printf("\n0. Fim\t\t\t3. Quantidade de Nodos\t\t6. Exibe Fila");
    printf("\n1. Insere\t\t4. Exibe situação da fila\t7. Consulta por código");
    printf("\n2. Retira\t\t5. Consulta frente");
    printf("\nOperacao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1: // 1. Insere na fila
      printf("\nDigite o código para o dado a ser inserido: ");
      scanf("%d", &cod);
      
      do {
        resultado = confereCodigo(fila, &dado, cod);
        if (resultado == SUCESSO) {
          printf("\nCódigo já existente! Digite outro código: ");
          scanf("%d", &cod);
        }
      } while (resultado == SUCESSO);

      dado.cod = cod;
      printf("Digite o peso para o dado a ser inserido: ");
      scanf("%f", &dado.peso);
      if (insere(&fila, dado) == SUCESSO) {
        printf("\nOperacao Realizada com Sucesso!");
      } else {
        printf("\nOperacao NAO realizada: Faltou Memoria!");
      }
      break;

    case 2: // 2. Retira da fila
      if (retira(&fila, &dado) == SUCESSO) {
        printf("\nOperacao Realizada com Sucesso!");
      } else {
        printf("\nOperacao NAO realizada: Fila Vazia!");
      }
      break;

    case 3: // 3. Quantidade de nodos
      printf("\nQuantidade de Nodos: %d", quantidadeDeNodos(fila));
      break;

    case 4: // 4. Exibe situação da fila
      if (estaVazia(fila) == FILA_VAZIA) {
        printf("\nA fila está vazia!");
      } else {
        printf("\nA fila possue 1 ou mais Nodos!");
      }
      break;

    case 5: // 5. Consulta frente
      consulta(fila, &dado);
      printf("\nDado na frente da fila:\nCod: %d\nPeso: %.2f", dado.cod, dado.peso);
      break;

    case 6: // 6. Exibe fila
      exibe(fila);
      break;
    
    case 7: // 7. Consulta por código
      printf("\nDigite o código a ser consultado: ");
      scanf("%d", &cod);
      if (confereCodigo(fila, &dado, cod) == SUCESSO) {
        printf("\nCódigo encontrado!");
        printf("\nDado:\nCod: %d\nPeso: %.2f", dado.cod, dado.peso);
      } else {
        printf("\nCódigo Inexistente!");
      }
      break;

    default:
      printf("\nOperação inválida!");
    }
    printf("\n-------------------------------------------\n");
    exibe(fila);
    printf("\n-------------------------------------------\n");
  } while (opcao != 0);

  return (0);
}