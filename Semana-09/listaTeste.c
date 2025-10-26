#include <stdio.h>
#include <stdlib.h>
#include "ListaSE.h"

int main() {
  int opcao, cod, resultado;
  ListaSE lista;
  Dado dado;

  criaLista(&lista);

  do {
    printf("\n0. Fim\t\t\t\t5. Inclui no Início\t\t8. Exclui do Início");
    printf("\n1. Exibe Lista\t\t\t6. Inclui Depois\t\t9. Exclui do Fim");
    printf("\n2. Quantidade de Nodos\t\t7. Inclui no Fim\t\t10. Exclui Nodo");
    printf("\n3. Exibe Situação da Lista\n4. Consulta por Código");
    printf("\nOperacao: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1: // 1. Exibe Lista
        exibe(lista);
      break;

      case 2: // Quantidade de Nodos
        printf("\nQuantidade de Nodos = %d", quantidadeDeNodos(&lista));
      break;

      case 3: // Exibe situação da lista
        if (estaVazia(lista) == LISTA_VAZIA) {
          printf("\nA lista está vazia!");
        } else {
          printf("\nA lista possue 1 ou mais Nodos!");
        }
        break;
      
      case 4: // 4. Consulta por código
        printf("\nDigite o código a ser consultado: ");
        scanf("%d", &cod);

        resultado = consultaPorCodigo(&lista, &dado, cod);

        if (resultado == LISTA_VAZIA) {
          printf("\nA lista está vazia!");
        }
        else if (resultado == CODIGO_INEXISTENTE) {
          printf("\nCódigo não encontrado na lista.");
        }
        else {
          printf("\nSucesso ao encontrar o dado pelo Código!");
          printf("\nDado:\nCódigo: %d\nPeso: %.2f", dado.cod, dado.peso);
        }
        break;

      case 5: // 5. Inclui no início
        printf("\n[cd] [peso]");
        scanf(" %d %f", &dado.cod, &dado.peso);
        if (incluiNoInicio(&lista, dado) == SUCESSO)
          printf("\nOperacao Realizada com Sucesso!");
        else
          printf("\nOperacao NAO realizada: Faltou Memoria!");
        break;
    
    case 6:  // 6. Inclui depois
        printf("\n[cd] [peso]");
        scanf(" %d %f", &dado.cod, &dado.peso);

        printf("\nDigite o código a ser incluido após ele: ");
        scanf("%d", &cod);

        resultado = incluiDepois(&lista, dado, cod);

        if (resultado == CODIGO_INEXISTENTE) {
          printf("\nCódigo não encontrado na lista");
        }
        else if (resultado == FALTOU_MEMORIA) {
          printf("\nErro ao alocar memória!");
        }
        else {
          printf("\nSucesso ao inserir dado!");
        }
        break;

    case 7: // Inclui no fim
        printf("\n[cd] [peso]");
        scanf(" %d %f", &dado.cod, &dado.peso);
        
        if (incluiNoFim(&lista, dado) == SUCESSO) {
          printf("\nOperacao Realizada com Sucesso!");
        }
        else {
          printf("\nOperacao NAO realizada: Faltou Memoria!");
        }
        break;

    case 8: // Exclui do inicio
        resultado = excluiDoInicio(&lista, &dado);

        if (resultado == LISTA_VAZIA) {
          printf("\nLista vazia!");
        }
        else {
          printf("\nDado excluído com sucesso!");
          printf("\nDado Excluído:\nCod: %d\nPeso: %.2f", dado.cod, dado.peso);
        }
        break;

    case 9: // Exclui do fim
        resultado = excluiDoFim(&lista, &dado);

        if (resultado == LISTA_VAZIA) {
          printf("\nLista vazia!");
        }
        else {
          printf("\nDado excluído com sucesso!");
          printf("\nDado Excluído:\nCod: %d\nPeso: %.2f", dado.cod, dado.peso);
        }
        break;

    case 10: // Exclui nodo
        printf("\nDigite o código do Nodo a ser excluído: ");
        scanf("%d", &cod);

        resultado = excluiNodo(&lista, &dado, cod);

        if (resultado == LISTA_VAZIA) {
          printf("\nLista vazia!");
        }
        else if (resultado == CODIGO_INEXISTENTE) {
          printf("\nCódigo não encontrado na lista!");
        }
        else {
          printf("\nNodo excluído com SUCESSO!");
          printf("\nNodo Excluído:\nCod: %d\nPeso: %.2f", dado.cod, dado.peso);
        }
        break;
    
    default:
        printf("\nOperação inválida!");
    }
    printf("\n-------------------------------------------\n");
    printf("\n");
    exibe(lista);
    printf("\n-------------------------------------------\n");
  } while (opcao != 0);

  return (0);
}