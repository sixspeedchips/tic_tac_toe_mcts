//
// Created by finn on 1/14/20.
//

#include "computer_player.h"
#include "../model/utils.h"
#include <chrono>
#include <algorithm>
#include <iostream>
computer_player::computer_player() {
  this->turn_time = 1e9;

}
int computer_player::takeTurn(mcts *pMcts) {

  auto start = chrono::steady_clock::now();
  auto end = chrono::steady_clock::now();
  while(chrono::duration_cast<chrono::nanoseconds>(end - start).count() < this->turn_time){
    end = chrono::steady_clock::now();
    pMcts->step();
  }

  auto x =
      max_element(pMcts->getCurrentNode()->getChildren()->begin(),
          pMcts->getCurrentNode()->getChildren()->end(),
                  [](const pair<int, node *> &p1, const pair<int, node *> &p2) {
                    return p1.second->getWinPercent() < p2.second->getWinPercent();
                  });

  printMap(pMcts->getCurrentNode());
  PrintVector(pMcts->getCurrentNode()->getValidMoves());

  cout << x->first<< endl;
  return x->first;
}
