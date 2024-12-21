#include "visible.h"

class Snake : public Visible {
public:
	explicit Snake(INT x = 0, INT y = 0, INT length = D_SNAKE_SIZE);
	void move(DIRECTION dir) override;
    INT getWidth() const override { return size; }
    INT getHeight() const override { return 1; }
private:
 // CHAR symbol;
 // CONTAINER_COORDINATES coordinates;
	INT size;
	DIRECTION direction;
};

Snake::Snake(INT x, INT y, INT length)
    : Visible('O', x, y), size(length), direction(right)
{
    for(INT i = 1; i != size; ++i)
        Visible::setXY().push_back(Coordinates(x - i, y));
}

void Snake::move(DIRECTION dir)
{
    if(dir == direction * -1)
        return;
    direction = dir;
	Coordinates tmp = *(setXY().begin());
    Visible::move(direction); // move the head
    auto i = setXY().begin();
    for(++i; i != setXY().end(); ++i) // move the body
        std::swap(tmp, *i);
}

//
// VISIBLE.H
//
Visible * Visible::makeSnake(INT x, INT y, INT length)
{
	return new Snake(x, y, length);
}