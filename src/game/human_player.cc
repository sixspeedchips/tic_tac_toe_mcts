//
// Created by finn on 1/13/20.
//

#include <iostream>
#include <algorithm>
#include "human_player.h"
#include "../model/node.h"
#include "../model/mcts.h"
int human_player::takeTurn(mcts *pMcts) {
  pMcts->step();
  int i;
  cout << "Play a move: ";
  cin >> i;
  i--;
  const vector<int> valid_moves = pMcts->getCurrentNode()->getValidMoves();
  while (count(valid_moves.begin(), valid_moves.end(), i)==0){
    cout << "Play a move: ";
    cin >> i;
    i--;
  }
  return i;
}
human_player::human_player() {

}
