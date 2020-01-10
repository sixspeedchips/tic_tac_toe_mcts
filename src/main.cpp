#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "model/node.h"
#include "model/tree.h"

using namespace std;



int main() {
  tree* mcts_tree = new tree(new node);
  mcts_tree->GetRoot()->AddChild(0)->AddChild(1)->AddChild(2)->AddChild(3);

  mcts_tree->traverse();

}
