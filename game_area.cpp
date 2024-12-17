#include "visible.h"

class GameArea : public Visible {
public:
    GameArea(INT posX, INT posY, INT width = D_AREA_SIZE_X, INT height = D_AREA_SIZE_Y)
        : Visible('.', posX, posY), width_(width), height_(height) {}
    void show() const  override;
private:
    INT width_, height_;
};

void GameArea::show() const
{
    for(INT y = 0; y != height_; ++y) {
        for (INT x = 0; x != width_; ++x)
            Visible::show();
        std::cout.put('\n');
    }
}

//
// VISIBLE.H
//
Visible * Visible::makeGameArea(INT x, INT y, INT w, INT h)
{
	return new GameArea(x, y, w, h);
}