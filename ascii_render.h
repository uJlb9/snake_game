#ifndef SNAKE_GAME_ASCII_RENDER_H
#define SNAKE_GAME_ASCII_RENDER_H

#include "visible.h"
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
    for(INT y = 0; y < data->getHeight(); ++y) {
        std::cout << "\t\t\t\t";
        for (INT x = 0; x < data->getWidth(); ++x)
            std::cout << data->getMatrix()[y][x];
        std::cout.put('\n');
    }
    std::cout.put('\n');
}

#endif //SNAKE_GAME_ASCII_RENDER_H