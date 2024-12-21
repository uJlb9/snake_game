#ifndef SNAKE_GAME_ASCII_RENDER_H
#define SNAKE_GAME_ASCII_RENDER_H

#include "visible.h"
#include <iostream>

class AsciiRenderer {
public:
    explicit AsciiRenderer(const CONTAINER_VISIBLE & scene);
    ~AsciiRenderer();
    void calculate();
    void render();
private:
    CONTAINER_VISIBLE const *scene_ptr;
    CHAR **matrix;
    INT width, height;
};

AsciiRenderer::AsciiRenderer(const CONTAINER_VISIBLE & scene)
    : scene_ptr(&scene), matrix(nullptr)
{
    for(auto i : *scene_ptr) {
        if(i->getChar() == '.') {
            width = i->getWidth();
            height = i->getHeight();
            break;
        }
    }
    matrix = new char *[height]{};
    for(INT y = 0; y < height; ++y)
        *(matrix + y) = new char[width]{};
}

AsciiRenderer::~AsciiRenderer()
{
    for(INT y = 0; y != height; ++y)
        delete [] *(matrix + y);
    delete [] matrix;
}

void AsciiRenderer::calculate()
{
    for(auto s : *scene_ptr)
        for(auto i = s->getXY().begin(); i != s->getXY().end(); ++i)
            matrix[i->y][i->x] = s->getChar();
}

void AsciiRenderer::render() // test
{
    for(INT y = 0; y < height; ++y) {
        std::cout.put('\t');
        for (INT x = 0; x < width; ++x)
            std::cout << matrix[y][x];
        std::cout.put('\n');
    }
    std::cout.put('\n');
}

#endif //SNAKE_GAME_ASCII_RENDER_H