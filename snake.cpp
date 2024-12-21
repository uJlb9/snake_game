#include "visible.h"

class Snake : public Visible {
public:
	explicit Snake(INT x = 0, INT y = 0, INT length = D_SNAKE_SIZE);
	void move(DIRECTION dir) override;
    void show() const override;
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
    if(direction == dir)
        return;
    direction = dir;
	
}

void Snake::show() const // test
{
    std::cout << "snake size: " << size << "\n";
    auto i = getXY().begin();
    for( ; i != getXY().end(); ++i)
        std::cout << '[' << i->x << ',' << i->y << ']';
    std::cout << '\n';
}

//
// VISIBLE.H
//
Visible * Visible::makeSnake(INT x, INT y, INT length)
{
	return new Snake(x, y, length);
}