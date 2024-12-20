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

	Visible(CHAR symbol, INT x, INT y) : symbol_(symbol), pos_() { pos_.push_back(Pos(x, y)); }
	virtual ~Visible() = default;
	virtual void move(DIRECTION);
	[[nodiscard]] virtual const CONTAINER& getPos() const { return pos_; }
    virtual CONTAINER & setPos() { return pos_; }
private:
	CHAR symbol_;
	CONTAINER pos_;
};

inline void Visible::move(DIRECTION dir)
{
    auto i = pos_.begin();
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