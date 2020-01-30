//
// Created by finn on 1/8/20.
//

#include <utility>
#include <numeric>
#include <vector>
#include <iostream>
#include "node.h"
#include "utils.h"

using namespace std;


map<int, node *> *node::getChildren() {
  return &this->children;
}

node::node(node *parent, vector<int> state, int move) {
  this->parent = parent;
  this->state = std::move(state);
  this->move = move;
  this->setTurn();
  this->state[move] = this->turn;

}

node::node() {
  this->parent = nullptr;
  this->turn = 1;
  this->state = vector<int>(9);
}


vector<int> node::getValidMoves() {
  vector<int> valid_moves;
  for (int i = 0; i < 9; i++) {
    if (this->state[i] == 0) {
      valid_moves.push_back(i);
    }
  }
  return valid_moves;
}
vector<int> node::getCurrentState() {
  return this->state;
}

int node::getTurn() {
 return this->turn;
}
void node::setTurn(){
  int sum = accumulate(begin(this->state), end(this->state), 0);
  if (sum == 0) {
    this->turn = 1;
  } else {
    this->turn = -1;
  }
}

node *node::getParent() {
  return this->parent;
}
node *node::getChild(int next_move) {
  vector<int> next_state(9);
  copy(this->state.begin(), this->state.end(), next_state.begin());
  node *child_node = new node(this, next_state, next_move);
  return child_node;
}

void node::addChild(node *node) {
  this->children[node->move] = node;
}

int node::win() {
  int sum;
  for (int i = 0; i < 3; i++) {
    sum = accumulate(begin(this->state) + i * 3,
                     begin(this->state) + i * 3 + 3,
                     0);

    if (abs(sum) == 3) {
      return sum / 3;
    }
    sum = this->state[i] + this->state[i + 3] + this->state[i + 6];
    if (abs(sum) == 3) {
      return sum / 3;
    }
  }
  sum = this->state[0] + this->state[4] + this->state[8];
  if (abs(sum) == 3) {
    return sum / 3;
  }
  sum = this->state[2] + this->state[4] + this->state[6];
  if (abs(sum) == 3) {
    return sum / 3;
  }
  if (this->getValidMoves().empty()) {
    return INT8_MIN;
  }
  return 0;
}

void node::update(int outcome, double p_played) {
  this->played += 1;
  this->parent_played = p_played;
  if(outcome == this->turn){
    this->wins += 1;
  } else if(outcome == INT8_MIN){
    this->wins += 1;
  }
  this->win_percent = this->wins/this->played;
  this->uct = this->win_percent + sqrt(2 * log2(this->parent_played) / this->played);
}

double node::getUct() {
  return this->uct;
}
double node::getPlayed() {
  return this->played;
}
double node::getWinPercent() {
  return this->win_percent;
}
int node::getMove() {
  return this->move;
}
void node::visited() {
  this->played += 1;
}
void node::setParent(node *pNode) {
  this->parent = pNode;
}
