//
// Created by finn on 1/10/20.
//
#include <vector>
#include <iostream>
using namespace std;

#ifndef TIC_TAC_TOE_MCTS_UTILS_H
#define TIC_TAC_TOE_MCTS_UTILS_H

void PrintVector(vector<int> v){

  for(auto elem: v){
    cout << elem;
  }
  cout << endl;
}

#endif //TIC_TAC_TOE_MCTS_UTILS_H
