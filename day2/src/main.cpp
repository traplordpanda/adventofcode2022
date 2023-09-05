#include <iostream>
#include <string_view>
#include <iostream>
#include "io.hpp"

int main() {
  using namespace std::string_view_literals;
  constexpr auto fname = "resources/input.mhtml"sv;
  auto score = get_data(fname); 
  std::cout << "total score : " << score << '\n';
}
