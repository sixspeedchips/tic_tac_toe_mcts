cmake_minimum_required(VERSION 3.15)
project(tic_tac_toe_mcts)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(tic_tac_toe_mcts main.cpp model/node.cc model/node.h model/tree.cc model/tree.h model/mcts.cc model/mcts.h model/tree.cc model/tree.h model/utils.h game/game.cc game/game.h game/player.cc game/player.h game/human_player.cc game/human_player.h game/computer_player.cc game/computer_player.h model/utils.cc)