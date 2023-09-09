#include "mp11_embed.hpp"
#include <fmt/core.h>

int main() {
  fmt::print("The Elf carrying the most Calories has: {} Calories.\n",
             MaxCalories::type::value);
  return 0;
}
