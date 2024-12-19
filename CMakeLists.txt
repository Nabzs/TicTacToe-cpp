cmake_minimum_required(VERSION 3.10)

project(TicTacToe)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(TicTacToe 
    tictactoe/main.cpp
    tictactoe/Player.cpp
    tictactoe/TicTacToe.cpp
)