cmake_minimum_required(VERSION 3.10)

project(TicTacToe)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(TicTacToe 
    src/main.cpp
    src/Player.cpp
    src/TicTacToe.cpp
)

target_include_directories(TicTacToe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(CMAKE_EXE_LINKER_FLAGS "-static -Wl,-subsystem,console")
