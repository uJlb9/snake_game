#ifndef SNAKE_GAME_ASCII_RENDER_H
#define SNAKE_GAME_ASCII_RENDER_H

#include "game_object.h"
#include "calculate_scene.h"
#include <iostream>

class AsciiRenderer {
public:
    explicit AsciiRenderer(Data & d) : data(&d) {}
    void render();
private:
    Data *data;
};

void AsciiRenderer::render() // test
{
    INT width = data->getWidth();
    INT height = data->getHeight();
    CHAR *matrix = data->getMatrix();
    for(INT y = 0; y < height; ++y) {
        for (INT x = 0; x < width; ++x) {
            std::cout.put(matrix[y * width + x]);
        }
        std::cout.put('\n');
    }
    std::cout.put('\n');
}

#endif //SNAKE_GAME_ASCII_RENDER_H