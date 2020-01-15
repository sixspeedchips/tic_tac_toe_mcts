#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "model/node.h"
#include "model/tree.h"
#include "model/mcts.h"
#include "game/game.h"
#include "game/human_player.h"
#include "game/computer_player.h"

using namespace std;


int main() {
//  mcts* pMcts = new mcts(new tree(new node));
//  for (int i = 0; i < 100; ++i) {
//    pMcts->step();
//  }
//  pMcts->getTree()->traverse();
  player *playerOne = new computer_player;
  player *playerTwo = new human_player;
  game *pGame = new game(playerOne, playerTwo);
  while (true){
    pGame->start();
    pGame->newGame();
  }
}
