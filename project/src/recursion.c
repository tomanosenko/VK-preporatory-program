#include <stdio.h>
#include <stdlib.h>


int rec(int count, int n) {
  printf("%i", count);
  if (abs(count) >= abs(n))
    return n;
  printf(" ");
  if (n > 0)
    return rec(count + 1, n);
  else
    return rec(count - 1, n);
}
