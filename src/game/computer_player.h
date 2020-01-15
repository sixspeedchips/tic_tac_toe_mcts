//
// Created by finn on 1/14/20.
//

#ifndef TIC_TAC_TOE_MCTS_COMPUTER_PLAYER_H
#define TIC_TAC_TOE_MCTS_COMPUTER_PLAYER_H


#include "player.h"
class computer_player : public player {
 private:
  long turn_time;
 public:
  computer_player();
  int takeTurn(mcts *pMcts) override;
};


#endif //TIC_TAC_TOE_MCTS_COMPUTER_PLAYER_H
