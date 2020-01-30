//
// Created by finn on 1/13/20.
//

#ifndef TIC_TAC_TOE_MCTS_HUMAN_PLAYER_H
#define TIC_TAC_TOE_MCTS_HUMAN_PLAYER_H


#include "player.h"
class human_player: public player {

 public:
  human_player();
  int takeTurn(mcts *pMcts) override;
};


#endif //TIC_TAC_TOE_MCTS_HUMAN_PLAYER_H
