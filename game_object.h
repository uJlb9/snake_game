#ifndef SNAKE_GAME_OBJECT_H
#define SNAKE_GAME_OBJECT_H

#include <iostream>
#include <vector> // snake.cpp
#include <list> // snake.cpp
#include "types.h"
#include "defaults.h"

class GameObject {
public:
    static GameObject * makeSnake(INT x = 4, INT y = 3, INT size = D_SNAKE_SIZE); // SNAKE.CPP
	static GameObject * makeApple(INT x, INT y); // APPLE.CPP
	static GameObject * makeGameArea(INT x = 0, INT y = 0,
                                     INT w = D_AREA_SIZE_X,
                                     INT h = D_AREA_SIZE_Y); //GAME_AREA.CPP
	GameObject(Type type, const char *str_conditions, INT x, INT y);
	virtual ~GameObject() = default;
    virtual Type getType() const { return type; }
    virtual INT getCond() const { return condition; }
    virtual CHAR getCondChar() const { return arr_conditions.arr[condition]; }
    virtual void setCond(INT COND) { condition = COND; }
    virtual void move(Direction);
    virtual void resize(INT n, Coordinates &xy) {}
    virtual CONTAINER_COORDINATES & setXY() { return coordinates; }
	virtual const CONTAINER_COORDINATES & getXY() const { return coordinates; }
    virtual INT getWidth() const = 0;
    virtual INT getHeight() const = 0;
private:
    Type type;
    Conditions arr_conditions;
    INT condition;
	CONTAINER_COORDINATES coordinates;
};

inline GameObject::GameObject(Type type, const char *str_conditions, INT x, INT y)
    : type(type), arr_conditions(str_conditions), condition(STANDS_STILL), coordinates()
{
    coordinates.push_back(Coordinates(x, y));
}

inline void GameObject::move(Direction dir)
{
    auto i = coordinates.begin();
	switch(dir) {
	case left:
		--(i->x);
        this->setCond(MOVING_LEFT);
		break;
	case right:
		++(i->x);
        this->setCond(MOVING_RIGHT);
		break;
	case up:
		--(i->y);
        this->setCond(MOVING_UP);
		break;
	case down:
		++(i->y);
        this->setCond(MOVING_DOWN);
	}
}

#endif // SNAKE_GAME_OBJECT_H