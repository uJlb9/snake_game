#ifndef SNAKE_VISIBLE_H
#define SNAKE_VISIBLE_H

#include <iostream>
#include <vector> // snake.cpp
#include <list> // snake.cpp
#include "typedefs.h"
#include "defaults.h"

class Visible {
public:
	static Visible * makeSnake(); // SNAKE.CPP
	static Visible * makeApple(INT x, INT y); // APPLE.CPP
	static Visible * makeGameArea(INT x, INT y, INT w, INT h); //GAME_AREA.CPP

	Visible(char symbol, INT posX, INT posY) : symbol_(symbol), posX_(posX), posY_(posY) {}
	virtual ~Visible() = default;
	virtual void show() const;
	virtual void move(direction);
	[[nodiscard]] virtual INT getX() const { return posX_; }
	[[nodiscard]] virtual INT getY() const { return posY_; }
private:
	char symbol_;
	INT posX_, posY_;
};

inline void Visible::show() const
{
	std::cout.put(symbol_);
}

inline void Visible::move(direction dir)
{
	switch(dir) {
	case left:
		--posX_;
		break;
	case right:
		++posX_;
		break;
	case up:
		--posY_;
		break;
	case down:
		++posY_;
	}
}

#endif // SNAKE_VISIBLE_H