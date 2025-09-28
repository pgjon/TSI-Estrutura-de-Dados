#include <stdio.h>
#include <stdlib.h>
#include "filacf.h"

void criaFila(FilaCF *f){
     f->frente= 0;
     f->re= -1;
}

int insere(FilaCF *f,int dado){


}

int retira(FilaCF *f,int *dado){


}

int estaCheia(FilaCF f){


}

int estaVazia(FilaCF f){


}

int consulta(FilaCF f,int *dado){
/*    FilaCF f2;
    int i, d, resul, fr, re;
    
    fr= f.frente;
    re= f.re;
    criaFila(&f2);
    
    for (i=fr;i<=re;i++){
         retira(&f,&d);
         insere(&f2,d);
         if (*dado == d)
            resul= SUCESSO;
    }

    f.frente= fr;
    f.re= fr-1;
    for (i=f2.frente;i<=f2.re;i++){
         retira(&f2,&d);
         insere(&f,d);
    }
    return(resul);
/*
}

void exibeFila(FilaCF f){
     int i;
     for (i=f.frente;i<=f.re;i++)
         printf("%d ", f.v[i]);
     printf("\nFr= %d - Re= %d\n\n",f.frente, f.re);      
}
