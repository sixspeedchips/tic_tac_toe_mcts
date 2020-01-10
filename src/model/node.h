//
// Created by finn on 1/8/20.
//

#ifndef TIC_TAC_TOE_MCTS_NODE_H
#define TIC_TAC_TOE_MCTS_NODE_H


#include <map>
#include <vector>

using namespace std;

class node {

 private:
  map<int, node*> children;
  node* parent;
  int move = -1;
  vector<int> state;
  vector<int> valid_moves;
  int current_turn;
  void SetValidMoves();
  void SetTurn();

 public:
  node();
  node(node* parent, vector<int> state, int move);
  node* NextMove(int location);
  void AddChild(node *node);
  node* AddChild(int location);
  int GetLastMove();
  int GetCurrentTurn();
  map<int, node*> GetChildren();
  vector<int> GetValidMoves();
  vector<int> GetCurrentState();
  node *getParent();

};


#endif //TIC_TAC_TOE_MCTS_NODE_H
