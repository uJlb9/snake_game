#include "game_object.h"

static const char *conditions_field{"..."};

class GameArea : public GameObject {
public:
    GameArea(INT x, INT y, INT width = D_AREA_SIZE_X, INT height = D_AREA_SIZE_Y);
    INT getWidth() const override { return width; }
    INT getHeight() const override { return height; }
private:
    INT width, height, max_x, max_y;
};

GameArea::GameArea(INT x, INT y, INT w, INT h)
    : GameObject(t_field, conditions_field, x, y), width(w), height(h),
      max_x(x + w - 1), max_y(y + h - 1)
{
    for(INT Y = y; Y <= max_y; ++Y) {
        for(INT X = x; X <= max_x; ++X) {
            GameObject::setXY().push_back(Segment(X, Y));
        }
    }
}

//
// GAME_OBJECT.H
//
GameObject * GameObject::makeGameArea(INT x, INT y, INT w, INT h)
{
	return new GameArea(x, y, w, h);
}