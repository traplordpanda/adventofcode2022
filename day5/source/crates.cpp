#include "crates.hpp"
#include <algorithm>
#include <cctype>
#include <fmt/core.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

/******** Creates Definition **********/
Crates::Crates(std::size_t s) : col_count(s), data(s){};

auto Crates::display_crates() const -> void {
  auto idx = 0;
  for (auto row : data) {
    std::cout << ++idx << ' ';
    for (auto c : row) {
      std::cout << c;
    }
    std::cout << '\n';
  }
}

auto Crates::move_crate(std::size_t fromc, std::size_t toc) -> void {
  auto &movee = data.at(fromc);
  auto move = movee.at(movee.size() - 1);
  data.at(toc).emplace_back(move);
  movee.pop_back();
}

auto Crates::move_crate(std::size_t fromc, std::size_t toc, std::size_t amount) -> void {
  auto &source = data.at(fromc);
  auto &destination = data.at(toc);

  // Verify if enough crates to move
  if (source.size() < amount)
    throw std::runtime_error("Not enough crates to move.");

  // We will transfer `amount` crates from the end of source to the end of
  // destination.
  for (size_t i = 0; i < amount; ++i) {
    destination.push_back(source[source.size() - amount + i]);
  }

  // Now, remove the `amount` crates from the source.
  source.resize(source.size() - amount);
}

auto Crates::order9000(command &c) -> void {
  for (size_t i = 0; i < c.amount; ++i) {
    move_crate(c.fromc - 1, c.toc - 1);
  }
}

auto Crates::order9001(command &c) -> void {
  move_crate(c.fromc - 1, c.toc - 1, c.amount);
}

auto Crates::add_row(std::string_view sv) -> void {
  auto get_dq_idx = [](int i) { return (i - 1) / 4; };
  size_t idx = 1;
  while (idx < sv.size()) {
    char c = sv.at(idx);
    if (c != ' ') {
      auto &v = data.at(get_dq_idx(idx)); 
      auto it = v.begin();
      v.insert(it, c);
    }
    idx += 4;
  }
}

auto Crates::print_top_row() const -> void {
  for (auto &col : data) {
    std::cout << col.back();
  }
  std::cout << '\n';
}

/******** Creates Definition **********/

auto col_calc(std::istream &ss) -> size_t {
  std::string line;
  std::getline(ss, line);
  auto sz = (line.size() + 1) / 4;
  ss.clear();
  ss.seekg(0, std::ios::beg);
  return sz;
}

auto istate_builder(std::istream &ss) -> Crates {
  std::string line;
  auto sz = col_calc(ss);
  Crates c(sz);
  while (std::getline(ss, line)) {
    if (std::isdigit(line[1])) {
      break;
    }
    c.add_row(line);
  }
  return c;
}

auto parse_command(std::string_view line) -> command {
  command c;
  std::stringstream ss;
  ss << line;
  ss >> c;
  return c;
}
