#include "game_object.h"

static const char *conditions_apple{"Aaa"};

class Apple : public GameObject {
public:
	Apple(INT x, INT y) : GameObject(t_apple, conditions_apple, x, y) {}
    INT getWidth() const override { return 1; }
    INT getHeight() const override { return 1; }
private:
};

//
// GAME_OBJECT.H
//
GameObject * GameObject::makeApple(INT x, INT y)
{
	return new Apple(x, y);
}