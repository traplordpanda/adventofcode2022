#include "crates.hpp"
#include <fmt/core.h>
#include <fstream>
#include <iostream>
#include <sstream>

import Cratemover;

using namespace std::string_view_literals;

/* f(1) = 3;
 * f(2) = 7;
 * f(3) = 11;
 * f(4) = 15;
 * f(x) = 4*x - 1 = (y + 1)/4
 */

auto gen_lines(std::stringstream &ss) -> std::vector<std::string> {
  std::string line;
  std::vector<std::string> lines;
  while (std::getline(ss, line)) {
    lines.emplace_back(line);
  }
  return lines;
}

int main() {
  constexpr auto initial_state = "[Y]     [B]\n"
                                 "[T]     [X]\n"
                                 "[O] [U] [H]\n"
                                 " 1   2   3 \n"
                                 " 2   3   4 \n"sv;
  std::stringstream ss;
  ss << initial_state;
  auto crates = istate_builder(ss);
  std::string command_input{"move 1 from 3 to 2"};
  auto c = parse_command(command_input);
  crates.order(c);
  crates.display_crates();
  c.print();
  std::cout << '\n';
  fmt::print("{}", initial_state);
  return 0;
}
