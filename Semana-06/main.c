/*
    
*/
# include <stdio.h>
# include <stdlib.h>
# include <locale.h>
# include <windows.h>
# include "ListaCF.h"


int main(){
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Variables
    ListaCF lista;
    Dado dado;
    int op, cod, resultado, codRef;;

    // Inputs
    do {
        printf("\nMENU\n");
        printf("\n0.Fim\t\t\t\t5.Exclui do fim\t\t\t10.Exclui nodo\n");
        printf("1.Inclui no fim\t\t\t6.Inclui no início\n");
        printf("2.Exibe lista\t\t\t7.Exclui do início\n");
        printf("3.Quantidade de nodos\t\t8.Consulta por código\n");
        printf("4.Exibe situação da lista\t9.Inclui Antes\n");
        printf("\nOpção: ");
        scanf("%d", &op);

        switch (op) {
        case 0:
            break;
        case 1: // Inclui no fim
            printf("Digite o código: ");
            scanf("%d", &cod);
            while (confereCod(lista, cod) == CODIGO_EXISTENTE) {
                printf("\nCódigo já existe na lista!\nCódigo: ");
                scanf("%d", &cod);
            }
            dado.cod = cod;

            printf("Digite o peso: ");
            scanf("%f", &dado.peso);

            resultado = incluiNoFim(&lista, dado);

            if (resultado == SUCESSO) {
                printf("\nDado inserido com SUCESSO!");
            }
            else {
                printf("\nLista está cheia!");
            }
            break;
        
        case 2: // Exibe lista
            exibe(lista);
            break;

        case 3: // Quantidade de nodos
            resultado = quantidadeDeNodos(lista);
            printf("\nQuantidade de nodos na Lista: %d", resultado);
            break;
        
        case 4: // Exibe situação da lista
            if (estaCheia(lista) == LISTA_CHEIA) {
                printf("\nA lista está Cheia!");
            }
            else if (estaCheia(lista) == LISTA_VAZIA) {
                printf("\nA lista está Vazia!");
            }
            else {
                printf("\nA lista possue 1 ou mais Nodos!");
            }
            break;

        case 5: // Exclui do fim
            resultado = excluiDoFim(&lista, &dado);
            if (resultado == LISTA_VAZIA) {
                printf("\nLista vazia!");
            }
            break;
        
        case 6: // Inclui no início
            printf("Digite o código: ");
            scanf("%d", &cod);
            while (confereCod(lista, cod) == CODIGO_EXISTENTE) {
                printf("\nCódigo já existe na lista!\nCódigo: ");
                scanf("%d", &cod);
            }
            dado.cod = cod;

            printf("Digite o peso: ");
            scanf("%f", &dado.peso);

            resultado = incluiNoInicio(&lista, dado);

            if (resultado == SUCESSO) {
                printf("\nDado inserido com SUCESSO!");
            }
            else {
                printf("\nLista está cheia!");
            }
            break;

        case 7: // Exclui do início
            resultado = excluiDoInicio(&lista, &dado);
            if (resultado == LISTA_VAZIA) {
                printf("\nLista vazia!");
            }
            break;
        
        case 8: // Consulta por código
            printf("\nDigite o código a ser pesquisado: ");
            scanf("%d", &cod);

            resultado = consultarPorCodigo(lista, cod, &dado);
            if (resultado == LISTA_VAZIA) {
                printf("\nLista vazia!");
            }
            else {
                printf("\nCódigo não encontrado na lista!");
            }
            break;
        
        case 9: // Inclui Antes
            printf("Digite o código de referência: ");
            scanf("%d", &codRef);
            while (confereCod(lista, codRef) != CODIGO_EXISTENTE) {
                printf("\nCódigo deve exister na lista!\nCódigo de referência: ");
                scanf("%d", &codRef);
            }

            printf("Digite o código do dado: ");
            scanf("%d", &cod);
            while (confereCod(lista, cod) == CODIGO_EXISTENTE) {
                printf("\nCódigo não pode exister na lista!\nCódigo: ");
                scanf("%d", &cod);
            }
            dado.cod = cod;

            printf("Digite o peso: ");
            scanf("%f", &dado.peso);

            resultado = incluiAntes(&lista, codRef, dado);

            if (resultado == SUCESSO) {
                printf("\nDado inserido com SUCESSO!");
            }
            else {
                printf("\nLista está cheia!");
            }
            break;
        
        case 10: // Exclui nodo
            printf("Digite o código: ");
            scanf("%d", &dado.cod);

            resultado = excluiNodo(&lista, dado.cod, &dado);

            if (resultado == LISTA_VAZIA) {
                printf("\nLista vazia!");
            }
            else {
                printf("\nCódigo inexistente na lista!");
            }
            break;

        default:
            printf("\nOpção inválida!");
            break;
        }

        exibeTracos();
    } while (op != 0);
    // Processing

    // Outputs
    printf("\nAté mais! Saindo do programa");
    fflush(stdout); // força imprimir antes do sleep

    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        Sleep(1000); // espera de 1000ms = 1s
    }

    return 0;
}