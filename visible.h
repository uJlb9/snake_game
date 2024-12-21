#ifndef SNAKE_VISIBLE_H
#define SNAKE_VISIBLE_H

#include <iostream>
#include <vector> // snake.cpp
#include <list> // snake.cpp
#include "types.h"
#include "defaults.h"

class Visible {
public:
    static Visible * makeSnake(INT size, INT x, INT y); // SNAKE.CPP
	static Visible * makeApple(INT x, INT y); // APPLE.CPP
	static Visible * makeGameArea(INT x, INT y, INT w, INT h); //GAME_AREA.CPP

	Visible(CHAR ch, INT x, INT y);
	virtual ~Visible() = default;
	
    virtual void move(DIRECTION);
    virtual CONTAINER_COORDINATES & setXY() { return coordinates; }
	virtual const CONTAINER_COORDINATES & getXY() const { return coordinates; }
    virtual CHAR getChar() const { return symbol; }
    virtual void setChar(CHAR ch) { symbol = ch; }
    virtual INT getWidth() const = 0;
    virtual INT getHeight() const = 0;
private:
    CHAR symbol;
	CONTAINER_COORDINATES coordinates;
};

inline Visible::Visible(CHAR ch, INT x, INT y) : symbol(ch), coordinates()
{
    coordinates.push_back(Coordinates(x, y));
}

inline void Visible::move(DIRECTION dir)
{
    auto i = coordinates.begin();
	switch(dir) {
	case left:
		--(i->x);
		break;
	case right:
		++(i->x);
		break;
	case up:
		--(i->y);
		break;
	case down:
		++(i->y);
	}
}

#endif // SNAKE_VISIBLE_H