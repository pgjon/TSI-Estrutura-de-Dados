#include <stdio.h>
int main() {
  int n, *p;
  n = 3;
  p = &n;
  printf("%p\n", p);
  return 0;
}
