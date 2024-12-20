#include "visible.h"

class GameArea : public Visible {
public:
    GameArea(INT posX, INT posY, INT width = D_AREA_SIZE_X, INT height = D_AREA_SIZE_Y)
        : Visible('.', posX, posY), width_(width), height_(height) {}
private:
    INT width_, height_;
};


//
// VISIBLE.H
//
Visible * Visible::makeGameArea(INT x, INT y, INT w, INT h)
{
	return new GameArea(x, y, w, h);
}