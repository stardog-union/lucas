#include <iostream>

#include "lucas.h"

int main(int argc, char* argv[]) {
#if defined(OS_MACOSX)
  std::cout << "OSX" << std::endl;
#elif defined(OS_SOLARIS)
  std::cout << "Solaris" << std::endl;
#elif defined(OS_AIX)
  std::cout << "AIX" << std::endl;
#elif defined(OS_LINUX)
  std::cout << "Linux" << std::endl;
#elif defined(OS_WINDOWS)
  std::cout << "Windows" << std::endl;
#else
  std::cout << "Unknown OS" << std::endl;
#endif
  for (long i = 0; i < 50; ++i) {
    std::cout << i << " " << fib(i) << std::endl;
  }
  return 0;
}
