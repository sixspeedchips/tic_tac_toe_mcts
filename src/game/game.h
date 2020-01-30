//
// Created by finn on 1/13/20.
//

#ifndef TIC_TAC_TOE_MCTS_GAME_H
#define TIC_TAC_TOE_MCTS_GAME_H


#include "../model/mcts.h"
#include "player.h"
class game {

 private:
    mcts *pMcts;
    vector<player*> * players;
 public:
    game(player *playerOne, player *playerTwo);
    void start();
    void newGame();
};


#endif //TIC_TAC_TOE_MCTS_GAME_H
