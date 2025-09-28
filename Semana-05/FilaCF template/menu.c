#include <stdio.h>
#include <stdlib.h>
#include "filacf.h"


int main()
{
  int op, dado;
  FilaCF fi;
  
  criaFila(&fi);
  
  do {
      printf("\n0. Fim  1.Insere  2.Retira  3.Exibe Situacao da Lista  4. Consulta  5.Exibe\n");
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
      }
      exibeFila(fi);            
    } while (op!=0);  
    
  return 0;
}
