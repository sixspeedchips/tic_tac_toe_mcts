//
// Created by finn on 1/9/20.
//

#ifndef TIC_TAC_TOE_MCTS_TREE_H
#define TIC_TAC_TOE_MCTS_TREE_H


#include "node.h"

class tree {
 private:
  node* root;

 public:
  tree(node *root);
  void traverse();
  node* GetRoot();
  void setRoot(node *pNode);
};


#endif //TIC_TAC_TOE_MCTS_TREE_H
