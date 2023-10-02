#include <cstddef> 
#include <fmt/core.h>
#include <fstream>
#include <sstream>
#include <string_view>
#include <vector>

struct command {
  uint32_t amount;
  uint32_t fromc;
  uint32_t toc;
  friend auto &operator>>(auto &ss, command &out) {
    std::string temp;
    ss >> temp >> out.amount >> temp >> out.fromc >> temp >> out.toc;
    return ss;
  }
  auto print() -> void {
    fmt::print("move {} from {} to {}\n", amount, fromc, toc);
  }
};

class Crates {
public:
  Crates(std::size_t s);
  auto order9000(command &c) -> void;
  auto order9001(command &c) -> void;
  auto display_crates() const -> void;
  auto width() const -> std::size_t { return col_count; }
  auto height() const -> std::size_t { return data.size(); }
  auto add_row(std::string_view sv) -> void;
  auto print_top_row() const -> void;

private:
  size_t col_count;
  std::vector<std::vector<char>> data;
  auto move_crate(std::size_t fromc, std::size_t toc) -> void;
  auto move_crate(std::size_t fromc, std::size_t toc, std::size_t amount) -> void;
};

auto istate_builder(std::istream &ss) -> Crates;
auto parse_command(std::string_view line) -> command;
