#include <stdio.h>
#include <stdlib.h>

void rec(int n) {
  if (n == 1)
    printf("%d", n);
  if (n > 1) {
    rec(n - 1);
    printf(" ");
    printf("%d", n);
  }
  if (n < 1) {
    rec(n + 1);
    printf(" ");
    printf("%d", n);
  }
}
