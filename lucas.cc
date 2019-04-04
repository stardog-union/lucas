#include "lucas.h"

#include <algorithm>
#include <cmath>
#include <random>
#include <vector>

namespace {

// Generate the prime factors of n.
inline std::vector<long> compute_prime_factors(long n) {
  std::vector<long> factors;
  if (n % 2 == 0) {
    factors.push_back(2);
    do {
      n = n / 2;
    } while (n % 2 == 0);
  }

  long limit = std::sqrt(n);
  for (long i = 3; i < limit; i += 2) {
    if (n % i == 0) {
      factors.push_back(i);
      do {
        n = n / i;
      } while (n % i == 0);
      limit = std::sqrt(n);
    }
  }

  if (n > 2) {
    factors.push_back(n);
  }
  return factors;
}

inline long modulus_exp(long x, long n, long q) {
  long result = 1;
  for (long i = 0; i < n; ++i) {
    result = (result * x) % q;
  }
  return result;
}

} // namespace

bool is_prime_lucas(long n, long k) {
  // Trivial checks.
  if (n < 2) {
    return false;
  }
  if (n == 2) {
    return true;
  }
  if (n % 2 == 0) {
    return false;
  }

  k = std::min(k, n - 2);

  std::vector<long> factors = compute_prime_factors(n - 1);

  std::random_device random_device;
  std::uniform_int_distribution<long> distribution{2, n - 1};
  std::vector<long> tried_values;
  for (long i = 0; i < k; ++i) {
    long a;
    do {
      a = distribution(random_device);
    } while (std::find(tried_values.begin(), tried_values.end(), a) != tried_values.end());

    if (modulus_exp(a, n - 1, n) != 1) {
      return false;
    }

    bool flag = true;
    for (size_t i = 0; i < factors.size(); ++i) {
      if (modulus_exp(a, (n - 1) / factors[i], n) == 1) {
        flag = false;
        break;
      }
    }

    if (flag) {
      return true;
    }
  }

  return false;
}
