//
// Created by finn on 1/13/20.
//

#include <iostream>
#include <limits>
#include "game.h"
#include "../model/utils.h"

void game::newGame() {
  this->pMcts = new mcts(new tree(new node));
}
game::game(player *playerOne, player *playerTwo) {
  this->newGame();
  this->players = new vector<player *> {playerOne, playerTwo};
}

void game::start() {
  player *current_player;
  int c = 0;
  int move;
  int winner;
  while ((winner = this->pMcts->getCurrentNode()->win()) == 0) {
    system("clear");
    // rotates through the players
    current_player = players->at(c++ % 2);
    PrintBoard(this->pMcts->getCurrentNode()->getCurrentState());
    move = current_player->takeTurn(this->pMcts);
    this->pMcts->makeMove(move);
  }
  system("clear");
  PrintBoard(this->pMcts->getCurrentNode()->getCurrentState());
  if(winner == 1){
    cout << "X has won the game!" << endl;
  } else if (winner == -1){
    cout << "O has won the game!" << endl;
  } else {
    cout << "The game was a draw." << endl;
  }
  std::cout << "Press Enter to continue...\n"; while (std::cin.get()!='\n');
}

