#include "visible.h"

class Apple : public Visible {
public:
	Apple(INT x, INT y) : Visible('A', x, y) {}
};


//
// VISIBLE.H
//
Visible * Visible::makeApple(INT x, INT y)
{
	return new Apple(x, y);
}