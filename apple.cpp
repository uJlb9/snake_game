#include "visible.h"

class Apple : public Visible {
public:
	Apple(INT posX, INT posY) : Visible('A', posX, posY) {}
};


//
// VISIBLE.H
//
Visible * Visible::makeApple(INT x, INT y)
{
	return new Apple(x, y);
}