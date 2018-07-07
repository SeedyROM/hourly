cmake_minimum_required(VERSION 3.10)
set(EXEC_NAME space_invaders)
project(${EXEC_NAME})

set(CMAKE_CXX_STANDARD 17)

include_directories(lib)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(${EXEC_NAME} main.cpp src/Entity.cpp lib/Entity.h src/Filesystem.cpp lib/Filesystem.h src/TextureContext.cpp lib/TextureContext.h src/Renderer.cpp lib/Renderer.h)
target_link_libraries(${EXEC_NAME} sfml-graphics sfml-audio)
