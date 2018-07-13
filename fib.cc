#include <iostream>

#include "lucas.h"

constexpr long(*fib)(long) = &lucas<1, 1>;

int main(int argc, char* argv[]) {
  for (long i = 0; i < 50; ++i) {
    std::cout << i << " " << fib(i) << std::endl;
  }
  return 0;
}
