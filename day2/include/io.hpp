#include <fstream>
#include <string>
#include "engine.hpp"

auto get_data(std::string_view fname) -> int {
  std::string line;
  std::ifstream ifs(fname.data());
  int score = 0;
  if (ifs.is_open()) {
    while (std::getline(ifs, line)) {
      auto p1 = static_cast<hands>(line[0]);
      auto p2 = static_cast<hands>(line[2]);
      score += hand_score(p2);
      score += static_cast<int>(winner(p1, p2));
    }
    ifs.close();
  }
  return score;
}
