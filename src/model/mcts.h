//
// Created by finn on 1/10/20.
//

#ifndef TIC_TAC_TOE_MCTS_MCTS_H
#define TIC_TAC_TOE_MCTS_MCTS_H

#include "tree.h"


class mcts {

 public:
  mcts(tree *baseTree);
  void step();

  node *getRoot();
  tree *getTree();
  node *getCurrentNode();
  void makeMove(int move);

 private:
  tree *base_tree;
  node *selection();
  node *selectBestChild(node *pNode);
  node *randomChild(node *pNode);
  int simulation(node *pNode);
  node *expansion(node *pNode);
  void backPropagation(node *pNode, int outcome);
  double steps;
  node *current_node;
};


#endif //TIC_TAC_TOE_MCTS_MCTS_H
