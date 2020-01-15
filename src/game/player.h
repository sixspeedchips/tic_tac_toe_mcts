//
// Created by finn on 1/13/20.
//

#ifndef TIC_TAC_TOE_MCTS_PLAYER_H
#define TIC_TAC_TOE_MCTS_PLAYER_H


#include "../model/node.h"
#include "../model/mcts.h"
class player {

 public:
  virtual int takeTurn(mcts *pMcts) = 0;
};


#endif //TIC_TAC_TOE_MCTS_PLAYER_H
