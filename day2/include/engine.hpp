#include <algorithm>
#include <array>

/*
The first column is what your opponent is going to play: A for Rock,
B for Paper, and C for Scissors.
The second column, you reason, must be what you should play in response:
X for Rock, Y for Paper, and Z for Scissors. 
*/

/*
 *shape you selected (1 for Rock, 2 for Paper, and 3 for Scissors)
 *plus the score for the outcome of the round (0 if you lost, 3
 *if the round was a draw, and 6 if you won).
*/

enum class win_state : int { loss=0, tie=3, win=6 };

enum class hands : char {
  op_rock = 'A',
  op_paper = 'B',
  op_scissors = 'C',
  player_rock = 'X',
  player_paper = 'Y',
  player_scissors = 'Z'
};

constexpr auto weak_against_op =
    std::array{hands::op_rock, hands::op_paper, hands::op_scissors};

constexpr auto weak_against_player =
    std::array{hands::player_rock, hands::player_paper, hands::player_scissors};

template<typename hands, std::size_t size>
auto get_hands_idx(const std::array<hands, size> weak, hands hand) {
  return std::distance(
      weak.begin(),
      std::find(weak.begin(), weak.end(), hand));
};

auto hand_score(const hands hand) -> int
{
  auto p1idx = get_hands_idx(weak_against_player, hand);
  return p1idx + 1;
}

auto winner(const hands player1, const hands player2) -> win_state {
  auto p1idx = get_hands_idx(weak_against_op, player1);
  auto p2idx = get_hands_idx(weak_against_player, player2);
  if (p1idx == p2idx) {
    return win_state::tie;
  }
  return (p1idx == ((p2idx + 1) % 3) ? win_state::loss : win_state::win);
}


