#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

class Recaman final {
private:
  std::set<int64_t> available_{};

  int64_t n_{0};
  int64_t last_value_{0};
  int64_t max_value_{0};

  bool is_available(int64_t value) const {
    if (value > max_value_) {
      return true;
    }

    if (available_.find(value) != available_.end()) {
      return true;
    }

    return false;
  }

  // Mark the values on [start, finish) as available. If finish is less than or
  // equal to start, no values are marked.
  void mark_available(int64_t start, int64_t finish) {
    for (int64_t i = start; i < finish; ++i) {
      available_.insert(i);
    }
  }

  void mark_unavailable(int64_t value) { available_.erase(value); }

public:
  int64_t index() const { return n_; }

#ifndef __cpp_coroutines
  generator<int64_t> values() {
    co_yield next();
  }
#endif

  int64_t next() {
    int64_t next = last_value_ - n_;
    if (next <= 0 || !is_available(next)) {
      next = last_value_ + n_;
    }

    mark_unavailable(next);

    // Note that mark_available() does the right thing regardless whether the
    // sequence moves forwards or backwards.
    mark_available(max_value_ + 1, next);

    ++n_;
    last_value_ = next;
    max_value_ = std::max(max_value_, next);
    return next;
  }

  void reset() {
    n_ = 0;
    last_value_ = 0;
    max_value_ = 0;
    available_.clear();
  }

  ssize_t available_size() const {
    return available_.size();
  }

  void print_available() const {
    bool need_comma = false;
    for (int64_t value : available_) {
      if (need_comma) {
	std::cout << ", ";
      }
      std::cout << std::to_string(value);
      need_comma = true;
    }
    std::cout << "\n";
  }
};
