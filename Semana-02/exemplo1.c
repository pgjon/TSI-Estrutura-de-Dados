#include <stdio.h>
void troca(int x, int y);
int main() {
  int a, b;
  a = 3;
  b = 5;
  troca(a, b);
  printf("%d %d\n", a, b);
  return 0;
}
void troca(int x, int y) {
  int aux;
  aux = x;
  x = y;
  y = aux;
  printf("%d %d\n", x, y);
}