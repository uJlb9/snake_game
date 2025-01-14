cmake_minimum_required(VERSION 3.22)
project(snake_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(snake_game apple.cpp defaults.h main.cpp snake.cpp types.h game_object.h
               calculate_scene.h ascii_render.h game_field.h)
add_compile_options(-Wall -Wextra)