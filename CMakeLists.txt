cmake_minimum_required(VERSION 3.10)
project(space_invaders)

set(CMAKE_CXX_STANDARD 17)

include_directories(lib)

add_executable(space_invaders main.cpp src/SpriteAnimation.cpp lib/SpriteAnimation.h)