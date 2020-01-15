//
// Created by finn on 1/10/20.
//

#include <random>
#include <algorithm>
#include "mcts.h"

using namespace std;


mcts::mcts(tree *baseTree) {
  this->base_tree = baseTree;
  this->steps = 0;
  this->current_node = this->getRoot();
}


// performs one step in the MCTS process->
// selection->expansion->simulation->backpropagation
void mcts::step() {
  node *next_node = this->selection();
  if (next_node->win() != 0) {
    this->backPropagation(next_node, next_node->win());
  } else {
    node *expanded_node = this->expansion(next_node);
    int outcome = this->simulation(expanded_node);
    this->backPropagation(expanded_node, outcome);
  }

}

node *mcts::getRoot() {
  return this->base_tree->GetRoot();
}

tree *mcts::getTree() {
  return this->base_tree;
}

node *mcts::selection() {
  node *curr = this->current_node;
  while (!curr->getChildren()->empty()) {
    curr = selectBestChild(curr);
  }
  return curr;
}

node *mcts::selectBestChild(node *pNode) {
  return max_element(pNode->getChildren()->begin(), pNode->getChildren()->end(),
                     [](const pair<int, node *> &p1,
                        const pair<int, node *> &p2) {
                       return p1.second->getUct() < p2.second->getUct();
                     })->second;
}

node *mcts::expansion(node *pNode) {
  for (int idx: pNode->getValidMoves()) {
    pNode->addChild(pNode->getChild(idx));
  }
  return this->randomChild(pNode);
}

int mcts::simulation(node *pNode) {
  node *curr = pNode;
  vector<int> v;
  int idx;
  while (curr->win() == 0) {
    v = curr->getValidMoves();
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, v.size() - 1);
    // select a random move in the valid move vector
    idx = v.at(dist(mt));
    curr = curr->getChild(idx);
  }
  return curr->win();

}

node *mcts::randomChild(node *pNode) {
  auto it = pNode->getChildren()->begin();
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(0, pNode->getChildren()->size() - 1);
  advance(it, dist(mt));
  return pNode->getChildren()->at(it->first);
}
void mcts::backPropagation(node *pNode, int outcome) {
  this->getRoot()->visited();
  while (pNode->getParent() != nullptr) {
    pNode->update(outcome, pNode->getParent()->getPlayed() + 1);
    pNode = pNode->getParent();
  }
}
node *mcts::getCurrentNode() {
  return this->current_node;
}
void mcts::makeMove(int move) {
  this->current_node = this->current_node->getChildren()->at(move);
//  this->base_tree->setRoot(this->current_node);
//  this->current_node->setParent(nullptr);
}
