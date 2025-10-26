#include <stdio.h>
#include <stdlib.h>
#include "listase.h"

int main()
{
    int op,cd,peso;
    ListaSE lt;
    Dado d;
    
    criaLista(&lt);

    do {
      printf("\n0. Fim                         5. Exclui do Inicio         10. Exclui Nodo\n");    
      printf("1. Inclui no Inicio            6. Inclui no Fim            \n");    
      printf("2. Exibe Lista                 7. Exclui do Fim            \n");    
      printf("3. Quantidade de Nodos         8. Consulta por Codigo      \n");    
      printf("4. Exibe Situacao da Lista     9. Inclui Depois.           \n");
      printf("Operacao: ");    
      scanf("%d", &op);

      switch(op){
            case 1:
                 printf("[cd][peso]\n");
                 scanf (" %d %f", &d.cod,&d.peso);
                 if (incluiNoInicio(&lt, d)==0)
                    printf("Operacao Realizada com Sucesso!\n");
                 else
                    printf("Operacao NAO realizada: Faltou Memoria!");
                 break;
            case 3:
                 printf("Quantidade de Nodos= %d\n", quantidadeDeNodos(lt));
                 break;
      }
      exibe(lt);            
    } while (op!=0);  

  return(0);
}
