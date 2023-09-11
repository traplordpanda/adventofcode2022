#include <algorithm>
#include <fmt/core.h>
#include <span>
#include <string_view>
#include <tuple>

#include <fstream>
#include <string>
#include <vector>

const std::vector<std::string> read_lines(std::string_view filename) {
  std::ifstream ifs(filename.data());
  std::string line;
  std::vector<std::string> lines;
  while (std::getline(ifs, line)) {
    lines.emplace_back(line);
  }
  return lines;
}

int main() {
  using namespace std::string_view_literals;
  constexpr auto points =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"sv;
  auto point = [&points](const char c) {
    return std::distance(points.begin(),
                         std::find(points.begin(), points.end(), c)) +
           1;
  };
  const auto input = read_lines("resources/input.txt");
  int total = 0;

  auto fold_half_points = [&](const std::span<const char> &in) -> int {
    auto fold1 = std::span(in.data(), in.size() / 2);
    auto fold2 = std::span(in.data() + in.size() / 2, in.size() / 2);
    for (auto i : fold1) {
      for (auto k : fold2) {
        if (i == k) {
          auto pt = point(i);
          fmt::print("found {}\tpoint added {}\n", i, pt);
          return pt;
        }
      }
    }
    return 0;
  };

  for (const auto &test : input) {
    total += fold_half_points(test);
  }
  fmt::print("total points = {}\n", total);
  return 0;
}
