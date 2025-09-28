/*

*/
#include "FilaCF.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
  system("chcp 65001 > nul");
  setlocale(LC_ALL, "pt_BR.UTF-8");

  // Variables
  FilaCF fila;
  Dado dado;
  int opcao, cod, resultado, interacao = 1;
  // Inputs
  criaFila(&fila);

  do {
    printf("Interação nº %d\n\n", interacao);

    printf("Digite uma opção abaixo:\n");
    printf("\n0.Fim\t\t\t3.Quantidade de nodos\t\t6.Pesquisa dado");
    printf("\n1.Insere\t\t4.Exibe situação da fila");
    printf("\n2.Retira\t\t5.Consulta frente\n\nOpção: ");
    scanf("%d", &opcao);

    int confereCod = 1;
    switch (opcao) {
    case 1: // Insere
      printf("\nDigite o código: ");
      scanf("%d", &cod);
      do {
        confereCod = pesquisaValida(fila, cod);

        if (confereCod == SUCESSO) {
          printf("Código existente na fila!\n\nCódigo: ");
          scanf("%d", &cod);
        } else {
          dado.cod = cod;
        }
      } while (confereCod == SUCESSO);

      printf("Digite o peso: ");
      scanf("%f", &dado.peso);

      resultado = insere(&fila, dado);

      if (resultado == SUCESSO)
        printf("\nInserido com sucesso!\n");
      else
        printf("\nFalha: Fila está cheia!\n");
      break;

    case 2: // Retira
      resultado = retira(&fila, &dado);

      if (resultado == SUCESSO) {
        printf("\nRetirado:\nCod: %d\nPeso: %.2f\n", dado.cod, dado.peso);
      } else {
        printf("\nFalha: Fila está vazia!\n");
      }
      break;

    case 3: // Quantidade de nodos
      printf("\nQuantidade de nodos: %d\n", fila.re + 1);
      break;

    case 4: // Situação da fila
      exibe(fila);
      break;

    case 5: // Consulta frente
      resultado = consulta(fila, &dado);

      if (resultado == SUCESSO) {
        printf("\nFrente da fila:\nCod: %d\nPeso: %.2f\n", dado.cod, dado.peso);
      } else {
        printf("\nFalha: Fila está vazia!\n");
      }
      break;

    case 6: // Pesquisa código
      printf("\nDigite o código a ser pesquisado: ");
      scanf("%d", &cod);

      resultado = pesquisa(&fila, cod, &dado);

      if (resultado == SUCESSO) {
        printf("\nDado encontrado:\nCod: %d\nPeso: %.2f\n", dado.cod,
               dado.peso);
      } else {
        printf("\nFalha: Dado inexistente!\n");
      }
      break;
    }
    exibeTracos();
    interacao++;
  } while (opcao != 0);

  // Processing

  // Outputs
  printf("Até mais! Saindo do programa");
  fflush(stdout); // força imprimir antes do sleep

  for (int i = 0; i < 3; i++) {
    printf(".");
    fflush(stdout);
    Sleep(1000); // espera de 1000ms = 1s
  }

  return 0;
}