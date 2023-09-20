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
};

int main() {
  int total = 0;
  char temp;
  interval first, second;
  std::fstream in("resources/input.txt");
  while (in) {
    in >> first >> temp >> second;
    if (first.is_between(second)) {
      total++;
    }
  }

  fmt::print("Total in between {}\n", total);
  return 0;
}
