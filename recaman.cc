#include "recaman.h"

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  Recaman sequence;

  for (int64_t index = sequence.index(); index < 10000; index = sequence.index()) {
    sequence.next();
    std::cout << std::to_string(index) << ": " << std::to_string(sequence.available_size()) << std::endl;
  }

  return 0;
}
