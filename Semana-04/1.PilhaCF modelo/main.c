#include <stdio.h>
#include <stdlib.h>
#include "pilhacf.h"

int main(){
    int op;
    PilhaCF pl;
    // int d;
    
    criaPilha(&pl);

    do {
      printf("\n0. Fim                         5. Exibe Pilha\n");    
      printf("1. Empilha                     6. ConsultaTopo\n");    
      printf("2. Desempilha                  7. Pesquisa\n");    
      printf("3. Quantidade de Nodos\n");    
      printf("4. Exibe Situacao da Pilha\n");
      printf("Operacao: ");    
      scanf("%d", &op);

      switch(op){
            case 1:
 
                break;
            case 2:

                 break;
            case 3:

                 break;
            case 4:

                 break;
            case 6:

                 break;   
            case 7:

                 break;   
      }
      exibePilha(pl);            
    } while (op!=0);  
                 
  return 0;
}
