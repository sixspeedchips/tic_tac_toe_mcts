//
// Created by finn on 1/8/20.
//

#ifndef TIC_TAC_TOE_MCTS_NODE_H
#define TIC_TAC_TOE_MCTS_NODE_H


#include <map>
#include <vector>
#include <cmath>

using namespace std;

class node {

 private:
  node *parent;
  map<int, node *> children;
  int move = -1;
  vector<int> state;
  int turn;
  double played;
  double win_percent;
  double wins;
  double uct = INFINITY;
  double parent_played;
  void setTurn();

 public:
  node();
  node(node *parent, vector<int> state, int move);

  void addChild(node *node);
  node *getChild(int next_move);
  int getTurn();
  map<int, node *> *getChildren();
  vector<int> getValidMoves();
  vector<int> getCurrentState();
  node *getParent();
  int win();
  void update(int outcome, double p_played);
  double getUct();
  double getPlayed();
  double getWinPercent();
  int getMove();

  void visited();
  void setParent(node *pNode);
};


#endif //TIC_TAC_TOE_MCTS_NODE_H
