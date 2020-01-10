cmake_minimum_required(VERSION 3.15)
project(tic_tac_toe_mcts)

set(CMAKE_CXX_STANDARD 14)

add_executable(tic_tac_toe_mcts main.cpp model/node.cc model/node.h model/tree.cc model/tree.h model/tree.cc model/tree.h model/utils.h)