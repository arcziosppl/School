cmake_minimum_required(VERSION 3.27)
project(Statki)

set(CMAKE_CXX_STANDARD 17)

add_executable(Statki
        main.cpp
        Game/Board.cpp
        Game/Board.cpp
        Utils/Utils.cpp
        Utils/Utils.h
        Game/Player.cpp
        Game/Player.h)
