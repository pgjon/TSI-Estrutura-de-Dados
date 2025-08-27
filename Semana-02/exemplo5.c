#include <stdio.h>
void troca(int *x, int *y);

int main()
{
int a,b;
a=3;
b=5;
printf("A e B antes da manipulação:\na = %d b = %d\n", a, b);
troca(&a, &b);
printf("A e B depois da manipulação:\na = %d b = %d\n", a, b);
return 0;
}

void troca(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}
