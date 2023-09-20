#include <fmt/core.h>
#include <fstream>
#include <sstream>

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
    if ((this->min >= second.min && this->max <= second.max)) {
      return true;
    }
    return false;
  }
  auto overlaps(interval &second) -> bool {
    if ((this->min >= second.min && this->min <= second.max) ||
        (this->max <= second.max && this->max >= second.min)) {
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
    if (first.is_between(second) || second.is_between(first)) {
      total_between++;
    }
    if (first.overlaps(second) || second.overlaps(first)) {
      total_overlap++;
    }
  }

  fmt::print("Total in between {}\n", total_between);
  fmt::print("Total in overlaps{}\n", total_overlap);
  return 0;
}
