cmake_minimum_required(VERSION 3.27)
project(battle)

set(CMAKE_CXX_STANDARD 17)

add_executable(battle main.cpp
        Battle.cpp
        Battle.h
        Player.cpp
        Player.h
        Character.cpp
        Character.h
)
