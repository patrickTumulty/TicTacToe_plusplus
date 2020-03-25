cmake_minimum_required(VERSION 3.16.5)

project(TicTacToe_PlusPlus)

set(CMAKE_CXX_STANDARD 11)

add_executable(TicTacToe_PlusPlus 
    src/main.cpp 
    src/board.cpp 
    src/cli.cpp 
    src/player.cpp
    )