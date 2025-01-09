#include "game_object.h"

static const char *conditions_snake{"o,x<>^v"};
class Body;

class Snake : public GameObject {
public:
	explicit Snake(INT x = 0, INT y = 0, INT length = D_SNAKE_SIZE, Direction dir = right);
	void move(Direction dir) override;
    void resize(INT n, Coordinates &xy) override;
    INT getWidth() const override { return size; }
    INT getHeight() const override { return 1; }
private:
//  Type type;
//  Conditions arr_conditions;
//  INT condition;
//  CONTAINER_COORDINATES coordinates;
	INT size;
	Direction direction;
};

Snake::Snake(INT x, INT y, INT length, Direction dir)
    : GameObject(t_snake, conditions_snake, x, y), size(length), direction(dir)
{
    for(INT i = 1; i != length; ++i)
        GameObject::setXY().push_back(Coordinates(x - i, y));
}

void Snake::move(Direction dir)
{
    if(dir == direction * -1)
        return;
    direction = dir;
	Coordinates tmp = *(setXY().begin());
    GameObject::move(direction); // move the head
    auto i = setXY().begin();
    for(++i; i != setXY().end(); ++i) // move the body
        std::swap(tmp, *i);
}

void Snake::resize(INT n, Coordinates &xy)
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