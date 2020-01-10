//
// Created by finn on 1/8/20.
//

#include <iostream>
#include <utility>
#include <numeric>
#include "node.h"

using namespace std;

void node::AddChild(node *node) {
  this->children[node->move] = node;
}

int node::GetLastMove() {
  return this->move;
}

map<int, node *> node::GetChildren() {
  return this->children;
}
node::node(node *parent, vector<int> state, int move) {
  this->parent = parent;
  this->state = std::move(state);
  this->move = move;
  this->SetTurn();
  this->state[move] = this->GetCurrentTurn();
  this->SetValidMoves();

}

node::node() {
  this->parent=nullptr;
}

node* node::NextMove(int location) {
  vector<int> next_state(9, 0);
  copy(this->state.begin(), this->state.end(), next_state.begin());
  node *child_node = new node(this, next_state, location);
  return child_node;
}

int node::GetCurrentTurn() {
  return this->current_turn;
}

vector<int> node::GetValidMoves() {
  return this->valid_moves;
}
vector<int> node::GetCurrentState() {
  return this->state;
}

void node::SetValidMoves() {
  for (int i = 0; i < 9; i++) {
    if (this->state[i] == 0) {
      this->valid_moves.push_back(i);

    }
  }
}
void node::SetTurn() {
  int sum = accumulate(begin(this->state), end(this->state), 0);
  if (sum == 0) {
    this->current_turn = 1;
  } else {
    this->current_turn = -1;
  }
}
node *node::getParent() {
  return this->parent;
}
node* node::AddChild(int location) {
  vector<int> next_state(9, 0);
  copy(this->state.begin(), this->state.end(), next_state.begin());
  node *child_node = new node(this, next_state, location);
  AddChild(child_node);
  return child_node;
}
