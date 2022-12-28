cmake_minimum_required(VERSION 3.21)
project(projet_programmation_s5)

set(CMAKE_CXX_STANDARD 14)

add_executable(projet_programmation_s5 main.cpp Sources/Creation/Game.cpp Headers/Creation/Game.h Sources/Creation/Level.cpp Headers/Creation/Level.h Sources/Mobile/Mobile.cpp Headers/Mobile/Mobile.h Sources/Mobile/Player.cpp Headers/Mobile/Player.h Sources/Mobile/Fawn.cpp Headers/Mobile/Fawn.h Sources/Mobile/Lion.cpp Headers/Mobile/Lion.h Sources/Mobile/Tiger.cpp Headers/Mobile/Tiger.h Sources/Obstacle/Obstacle.cpp Headers/Obstacle/Obstacle.h Sources/Creation/Board.cpp Headers/Creation/Board.h Sources/Empty.cpp Headers/Empty.h Sources/Empty.cpp Headers/Empty.h Sources/Obstacle/Wall.cpp Headers/Obstacle/Wall.h)
