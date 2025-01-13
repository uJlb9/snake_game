#include "game_object.h"

static const char *conditions_snake{"o,xoooo__d"};
class Body;

class Snake : public GameObject {
public:
	explicit Snake(INT x = 0, INT y = 0, INT length = D_SNAKE_SIZE, Direction dir = right);
	void move(Direction dir) override;
    void resize(INT n, Segment &xy) override;
    INT getWidth() const override { return size; }
    INT getHeight() const override { return 1; }
    Direction getDir() { return direction; }
private:
	INT size;
	Direction direction;
};

Snake::Snake(INT x, INT y, INT length, Direction dir)
    : GameObject(t_snake, conditions_snake, x, y), size(length), direction(dir)
{
    for(INT i = 1; i != length; ++i)
        GameObject::setXY().push_back(Segment(x - i, y));
}

void Snake::move(Direction dir)
{
    if(dir == direction * -1)
        return;
    direction = dir;
	Segment tmp = *(setXY().begin());
    GameObject::move(direction); // move the head
    for(auto i= std::next(setXY().begin()) ; i != setXY().end(); ++i) // move the body
        std::swap(tmp, *i);
}

void Snake::resize(INT n, Segment &xy)
{
    size += n;
    for(INT i = 0; i != n; ++i)
        GameObject::setXY().push_back(xy);
}

//
// GAME_OBJECT.H
//
GameObject * GameObject::makeSnake(INT x, INT y, INT length)
{
	return new Snake(x, y, length);
}