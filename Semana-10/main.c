#include "ListaDE.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

// Constantes de retorno
#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

// ########################## MAIN ##########################
int main () {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int opcao, cod, resultado, codRef;
    ListaDE lista;
    Dado dado;

    criaLista(&lista);

    printf("\nLista Duplamente Encadeada\nBy: Jones Rodrigues\n");

    do {
        printf("\n################################# MENU DE OPÇÕES #################################");
        printf("\n _________________________________________________________________________________");
        printf("\n|                                                                                 |");
        printf("\n|0. Fim                 5. Exclui do Inicio         10. Consulta por Código       |");    
        printf("\n|1. Inclui no Inicio    6. Exclui do Fim            11. Gravar em Arquivo de Texto|");    
        printf("\n|2. Inclui no Fim       7. Exclui Nodo              12. Ler de Arquivo de Texto   |");    
        printf("\n|3. Inclui Depois       8. Quantidade de Nodos                                    |");    
        printf("\n|4. Exibe Lista         9. Exibe Situação da Lista                                |");
        printf("\n|_________________________________________________________________________________|");
        printf("\n\nOpção: ");    
        scanf("%d", &opcao);

        switch (opcao) {
        case 0: // Encerra o programa
            printf("\nAté mais! Saindo do programa");
            fflush(stdout); // força imprimir antes do sleep

            for (int i = 0; i < 3; i++) {
                printf(".");
                fflush(stdout);
                Sleep(1000); // espera de 1000ms = 1s
            }
            break;

        case 1: // Inclui no Inicio
            lerDadosValidos(&lista, &dado);
            resultado = incluiNoInicio(&lista, dado);

            if (resultado == SUCESSO) {
                printf("\nNodo incluído com SUCESSO!\n");
            }
            break;
        
        case 2: // Inclui no Fim
            lerDadosValidos(&lista, &dado);
            resultado = incluiNoFim(&lista, dado);

            if (resultado == SUCESSO) {
                printf("\nNodo incluído com SUCESSO!\n");
            }
            break;
        
        case 3: // Inclui Depois
            printf("\nDigite o código do Nodo de referência: ");
            scanf("%d", &codRef);

            lerDadosValidos(&lista, &dado);
            resultado = incluiDepois(&lista, dado, codRef);

            if (resultado == LISTA_VAZIA) {
                printf("\nLista vazia! Impossível incluir depois.");
            } else if (resultado == CODIGO_INEXISTENTE) {
                printf("\nCódigo de referência não encontrado na Lista!");
            } else {
                printf("\nNodo incluído com SUCESSO!\n");
            }
            break;
        
        case 4: // Exibe Lista
            exibeLista(lista);
            break;
        
        case 5: // Exclui do Inicio
            resultado = excluiNoInicio(&lista, &dado);

            if (resultado == LISTA_VAZIA) {
                printf("\nLista vazia! Impossível excluir.");
            } else {
                printf("\nNodo excluído com SUCESSO!\n");
            }
            break;
        
        case 6: // Exclui do Fim
            resultado = excluiNoFim(&lista, &dado);
            if (resultado == LISTA_VAZIA) {
                printf("\nLista vazia! Impossível excluir.");
            } else {
                printf("\nNodo excluído com SUCESSO!\n");
            }
            break;
        
        case 7: // Exclui Nodo
            printf("\nDigite o código do Nodo a ser excluido: ");
            scanf("%d", &cod);
            resultado = excluiNodo(&lista, &dado, cod);
    
            if (resultado == LISTA_VAZIA) {
                printf("\nLista vazia!\n");
            } else if (resultado == CODIGO_INEXISTENTE) {
                printf("\nCódigo não encontrado!\n");
            } else {
                printf("\nNodo excluído com SUCESSO!\n");
            }
            break;
        
        case 8: // Quantidade de Nodos
            printf("\nQuantidade de Nodos: %d", lista.n);
            break;
        
        case 9: // Exibe Situação da Lista
            exibeSituacaoDaLista(lista);
            break;
        
        case 10: // Consulta por Código
            printf("\nDigite o código do Nodo a ser pesquisado: ");
            scanf("%d", &cod);
            resultado = consultaPorCodigo(lista, &dado, cod);

            if (resultado == LISTA_VAZIA) {
                printf("\nLista vazia!");
            } else if (resultado == CODIGO_INEXISTENTE) {
                printf("\nCódigo não encontrado na Lista!");
            } else {
                printf("\nCod: %d\nPeso: %.2f", dado.cod, dado.peso);
            }
            break;
        
        case 11: // Gravar em Arquivo de Texto
            gravarArquivoTexto("dados-ListaDE.txt", &lista);
            break;
        
        case 12: // Ler de Arquivo de Texto
            lerArquivoTexto("dados-ListaDE.txt", &lista);
            break;
        
        default: // Opção inválida
            printf("\nOpção inválida!\n");
            break;
        }
    } while (opcao != 0);

    printf("\nAté mais! Saindo do programa");
    fflush(stdout); // força imprimir antes do sleep

    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        Sleep(1000); // espera de 1000ms = 1s
    }

    return 0;
}