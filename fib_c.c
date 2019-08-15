#include <stdio.h>

long fib(n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return fib(n-2) + fib(n-1);
  }
}

int main() {
  for (int i = 0; i < 50; ++i) {
    printf("%d: %ld\n", i, fib(i));
  }
  return 0;
}
