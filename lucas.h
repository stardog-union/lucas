#pragma once

/**
 * Sequence generator for Lucas sequences of the first kind. https://en.wikipedia.org/wiki/Lucas_sequence
 */
template <long p, long q>
long lucas_first(long n) {
  long current = 0;
  long previous = 1;
  for (long i = 1; i < n; ++i) {
    long next = p * current - q * previous;
    previous = current;
    current = next;
  }
  return current;
}

/**
 * Sequence generator for Lucas sequences of the second kind. https://en.wikipedia.org/wiki/Lucas_sequence
 */
template <int p, int q>
long lucas_second(long n) {
  long current = 2;
  long previous = p;
  for (long i = 1; i < n; ++i) {
    long next = p * current - q * previous;
    previous = current;
    current = next;
  }
  return current;
}
