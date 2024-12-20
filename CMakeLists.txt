cmake_minimum_required(VERSION 3.22)
project(snake_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(snake_game apple.cpp defaults.h game_area.cpp main.cpp snake.cpp types.h visible.h
        ascii_render.cpp
        ascii_render.h)
add_compile_options(-Wall -Wextra)