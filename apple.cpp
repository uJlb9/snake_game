#include "gameobject.h"

class Apple : public GameObject {
public:
	Apple(INT x, INT y) : GameObject(t_apple, conditions_apple, x, y) {}
    INT getWidth() const override { return 1; }
    INT getHeight() const override { return 1; }
private:

};

//
// VISIBLE.H
//
GameObject * GameObject::makeApple(INT x, INT y)
{
	return new Apple(x, y);
}