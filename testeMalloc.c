#include <stdio.h>
#include <stdlib.h>

int main() {
  float *p;
  p = (float *)malloc(sizeof(float));
  if (p == NULL)
    printf("Memória insuficiente\n");
  else {
    *p = 3.5;
    printf("Valor : % f\n", *p);
    free(p);
    printf("Valor : %.2f\n", *p);
  }
  return 0;
}