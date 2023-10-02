#include <deque>
#include <fmt/core.h>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#include "crates.hpp"

using namespace std::string_view_literals;

/* f(1) = 3;
 * f(2) = 7;
 * f(3) = 11;
 * f(4) = 15;
 * f(x) = 4*x - 1 = (y + 1)/4
 */
auto crate_mover_9000() {
  std::fstream file;
  file.open("../resources/input.txt");
  auto crates = istate_builder(file);
  crates.display_crates();
  std::string line;

  while (std::getline(file, line)) {
    if (line.starts_with("move")) {
      auto c = parse_command(line);
      crates.order9000(c);
    }
  }
  fmt::print("cratemover 9000 after parsing commands\n");
  crates.display_crates();
  crates.print_top_row();
}

auto crate_mover_9001() {
  std::fstream file;
  file.open("../resources/input.txt");
  auto crates = istate_builder(file);
  crates.display_crates();
  std::string line;

  while (std::getline(file, line)) {
    if (line.starts_with("move")) {
      auto c = parse_command(line);
      crates.order9001(c);
    }
  }
  fmt::print("cratemover 9001 after parsing commands\n");
  crates.display_crates();
  crates.print_top_row();
}
int main() {
  crate_mover_9000();
  crate_mover_9001();
  return 0;
}
