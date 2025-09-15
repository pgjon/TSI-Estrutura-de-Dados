#include <stdio.h>
#include <stdlib.h>
#include "pilhacf.h"

void criaPilha(PilhaCF *pl){
     pl->topo= -1;
}

void exibePilha(PilhaCF pl){
     int f;
     printf("Exibindo a Pilha\n");
     printf("[dado]\n");
     for (f=pl.topo;f >= 0;f--)
         printf("%4d\n", pl.v[f]);     
}

