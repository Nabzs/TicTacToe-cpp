cmake_minimum_required(VERSION 3.10)

project(Projet)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# TicTacToe
add_executable(TicTacToe 
    tictactoe/main.cpp
    tictactoe/Player.cpp
    tictactoe/TicTacToe.cpp
)

# Puissance4
# add_executable(Puissance4
#     puissance_4/main.cpp
#     puissance_4/Player.cpp
#     puissance_4/Puissance4.cpp
# )
