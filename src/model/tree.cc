//
// Created by finn on 1/9/20.
//

#include <stack>
#include "tree.h"
#include "utils.h"

tree::tree(node *root) {
  this->root = root;
}


void tree::traverse() {
  deque<node*> queue;
  queue.push_back(this->root);
  node* curr;
  while(!queue.empty()){
    curr = queue.at(0);
    queue.pop_front();
    for(auto elem: *curr->getChildren()){
      queue.push_back(elem.second);
    }
    printf("%.8f\n\n",curr->getWinPercent());
    PrintBoard(curr->getCurrentState());
//    PrintVector(curr->GetCurrentState());
//    PrintVector(curr->getValidMoves());
  }


}
node* tree::GetRoot() {
  return this->root;
}
void tree::setRoot(node *pNode) {
  this->root = pNode;
}
