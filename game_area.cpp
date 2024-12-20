#include "visible.h"

class GameArea : public Visible {
public:
    GameArea(INT x, INT y, INT width = D_AREA_SIZE_X, INT height = D_AREA_SIZE_Y);
private:
    INT width_, height_, max_x_, max_y_;
};

GameArea::GameArea(INT x, INT y, INT width, INT height)
    : Visible('.', x, y), width_(width), height_(height), max_x_(x + width_ - 1), max_y_(y + height_ - 1)
{}


//
// VISIBLE.H
//
Visible * Visible::makeGameArea(INT x, INT y, INT w, INT h)
{
	return new GameArea(x, y, w, h);
}