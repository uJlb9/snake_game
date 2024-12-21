#include "visible.h"

class Apple : public Visible {
public:
	Apple(INT x, INT y) : Visible('A', x, y) {}
    INT getWidth() const override { return 1; }
    INT getHeight() const override { return 1; }
private:
 // CHAR symbol;
 // CONTAINER_COORDINATES coordinates;
};

//
// VISIBLE.H
//
Visible * Visible::makeApple(INT x, INT y)
{
	return new Apple(x, y);
}