#ifndef SNAKE_GAME_CALCULATE_SCENE_H
#define SNAKE_GAME_CALCULATE_SCENE_H

#include "game_object.h"
#include <iostream>

class Data {
public:
    explicit Data(CONTAINER_GAME_OBJECTS & scene);
    ~Data();
    INT getWidth() const { return width; }
    INT getHeight() const { return height; }
    CHAR **& getMatrix() { return matrix; }
    void calculate();
    void jump(Coordinates& segment) const;
    void check_collision() const;
private:
    CONTAINER_GAME_OBJECTS *scene_ptr;
    CHAR **matrix;
    INT width, height;
};

Data::Data(CONTAINER_GAME_OBJECTS & scene)
    : scene_ptr(&scene), matrix(nullptr)
{
    for(auto s : *scene_ptr) {
        if(s->getType() == t_field) {
            width = s->getWidth();
            height = s->getHeight();
            break;
        }
    }
    // create an empty matrix
    matrix = new char *[height]{};
    for(INT y = 0; y < height; ++y)
        *(matrix + y) = new char[width]{};
}

Data::~Data()
{
    for(auto & i : *scene_ptr)
        delete i;
    for(INT y = 0; y != height; ++y)
        delete [] *(matrix + y);
    delete [] matrix;
}

void Data::calculate()
{
    for(auto obj = scene_ptr->begin(); obj != scene_ptr->end(); ++obj) {
        if ((*obj)->getCond() == DEAD) {
            delete *obj;
            obj = scene_ptr->erase(obj);
            continue;
        }
        for (auto &i: (*obj)->setXY()) {
            jump(i);
            matrix[i.y][i.x] = (*obj)->getCondChar();
        }
    }
    check_collision();
    for(auto & obj : *scene_ptr) {
        Type type = obj->getType();
        if(type == t_field)
            continue;
        for(auto & i : obj->getXY())
            matrix[i.y][i.x] = obj->getCondChar();
    }
}

void Data::jump(Coordinates &segment) const
{
    if(segment.x >= width) {
        segment.x = 0;
        return;
    } else if(segment.x < 0) {
        segment.x = width - 1;
        return;
    } else if(segment.y >= height) {
        segment.y = 0;
        return;
    } else if(segment.y < 0) {
        segment.y = height - 1;
        return;
    }
}

void Data::check_collision() const
{
    
    GameObject *snake;
    CONTAINER_COORDINATES::const_iterator head, tale;
    INT head_x, head_y, tale_x, tale_y;
    
    for(auto & obj : *scene_ptr) {
        if(obj->getType() != t_snake)
            continue;
        snake = obj;
        head = obj->getXY().begin();
        tale = std::prev(obj->getXY().end());
        break;
    }
    
    for(auto & obj : *scene_ptr) {
        Type type = obj->getType();
        if(type == t_field)
            continue;
        if(type == t_snake) {
            for(auto i = std::next(head); i != tale; ++i) {
                if(head->x == i->x && head->y == i->y) { // collision with the tale
                    snake->setCond(DEAD);
                    return;
                }
            }
        }
        if(type == t_apple) {
            auto apple = obj->getXY().begin();
            if(head->x == apple->x && head->y == apple->y) { // collision with an apple
                obj->setCond(HIDDEN);
            } else if(tale->x == apple->x && tale->y == apple->y) {
                obj->setCond(DEAD);
                snake->resize(1, *obj->setXY().begin());
            }
        }
    }
    
}

#endif //SNAKE_GAME_CALCULATE_SCENE_H