#pragma once

/**
 * Lucas sequence generator. https://en.wikipedia.org/wiki/Lucas_sequence
 */
template <int zeroth, int first>
long lucas(long n) {
  long current = zeroth;
  long previous = first;
  for (long i = 1; i < n; ++i) {
    long next = current + previous;
    previous = current;
    current = next;
  }
  return current;
}
