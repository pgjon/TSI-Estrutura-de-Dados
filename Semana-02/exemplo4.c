#include <stdio.h>
int main() {
  float x, *px;
  x = 2.5;
  px = &x;
  printf("%f\n", *px);
  return 0;
}