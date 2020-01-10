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
  stack<node*> stack;
  stack.push(this->root);
  node* curr;
  while(!stack.empty()){
    curr = stack.top();
    stack.pop();
    for(auto elem: curr->GetChildren()){
      stack.push(elem.second);
    }
    PrintVector(curr->GetCurrentState());
    PrintVector(curr->GetValidMoves());
    cout << endl;
  }


}
node* tree::GetRoot() {
  return this->root;
}
