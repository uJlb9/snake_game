#ifndef SNAKE_GAME_CALCULATE_SCENE_H
#define SNAKE_GAME_CALCULATE_SCENE_H

#include "visible.h"
#include <iostream>

class Data {
public:
    explicit Data(const CONTAINER_VISIBLE & scene);
    ~Data();
    INT getWidth() { return width; }
    INT getHeight() { return height; }
    CHAR **& getMatrix() { return matrix; }
    
    void calculate();
    bool outside(const Coordinates& segment) const;
    void jump(Coordinates& segment);
    bool collision(const Coordinates& segment) const;
private:
    CONTAINER_VISIBLE const *scene_ptr;
    CHAR **matrix;
    INT width, height;
};

Data::Data(const CONTAINER_VISIBLE & scene)
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

Data::~Data()
{
    for(INT y = 0; y != height; ++y)
        delete [] *(matrix + y);
    delete [] matrix;
}

void Data::calculate()
{
    for(auto s : *scene_ptr)
        for(auto i = s->setXY().begin(); i != s->setXY().end(); ++i) {
            if(outside(*i))
                jump(*i);
            matrix[i->y][i->x] = s->getChar();
        }
}

bool Data::outside(const Coordinates &segment) const
{
    return(segment.x >= width || segment.x < 0 || segment.y >= height || segment.y < 0);
}

void Data::jump(Coordinates &segment)
{
    if(segment.x >= width)
        segment.x = 0;
    if(segment.x < 0)
        segment.x = width - 1;
    if(segment.y >= height)
        segment.y = 0;
    if(segment.y < 0)
        segment.y = height - 1;
}

bool Data::collision(const Coordinates &segment) const
{
    
    return false;
}

#endif //SNAKE_GAME_CALCULATE_SCENE_H