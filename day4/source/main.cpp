#include <algorithm>
#include <cassert>
#include <cstdint>
#include <fmt/core.h>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ranges>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

using namespace std::string_view_literals;

struct interval {
  uint32_t min;
  uint32_t max;
  friend auto &operator>>(auto &in, interval &out) {
    char c;
    in >> out.min >> c >> out.max;
    return in;
  }
  auto is_between(interval &second) -> bool {
    if ((min >= second.min && max <= second.max) ||
        (second.min >= min && second.max <= max)) {
      return true;
    }
    return false;
  }
  auto overlap(interval &second) -> bool {
    if ((min >= second.min && min <= second.max) ||
        (max <= second.max && max >= second.min) ||
        (second.min >= min && second.min <= max) ||
        (second.max <= max && second.max >= min)) {
      return true;
    }
    return false;
  }
};

int main() {
  int total_between = 0;
  int total_overlap = 0;
  char temp;
  interval first, second;
  std::fstream in("resources/input.txt");
  while (in) {
    in >> first >> temp >> second;
    if (first.is_between(second)) {
      total_between++;
    }
    if (first.overlap(second)) {
      total_overlap++;
    }
  }

  fmt::print("Total in between {}\n", total_between);
  fmt::print("Total in between {}\n", total_overlap);
  return 0;
}
