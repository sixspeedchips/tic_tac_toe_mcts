//
// Created by finn on 1/14/20.
//

#include <functional>
#include "utils.h"

void PrintVector(const vector<int> &v) {
  for(auto elem: v){
    cout << elem;
  }
  cout << endl;
}
void PrintBoard(const vector<int> &v) {
  char a[9];
  int idx = 0;
  for (auto elem: v) {
    if(elem==1){
      a[idx]='X';
    } else if (elem==-1){
      a[idx]='O';
    } else{
      a[idx] = ' ';
    }
    idx++;
  }
  printf(" %c | %c | %c\n", a[0], a[1], a[2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", a[3], a[4], a[5]);
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", a[6], a[7], a[8]);
  cout << endl;

}
void printMap(node *pNode) {
    for(auto elem: *pNode->getChildren()){
    cout << elem.first <<" "<<elem.second->getWinPercent()<<endl;
  }

}
