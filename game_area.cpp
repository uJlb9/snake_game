#include "visible.h"

class GameArea : public Visible {
public:
    GameArea(INT x, INT y, INT width = D_AREA_SIZE_X, INT height = D_AREA_SIZE_Y);
    void show() const override;
    INT getWidth() const override { return width; }
    INT getHeight() const override { return height; }
private:
 // CHAR symbol;
 // CONTAINER_COORDINATES coordinates;
    INT width, height, max_x, max_y;
};

GameArea::GameArea(INT x, INT y, INT width, INT height)
    :   Visible('.', x, y), width(width), height(height),
        max_x(x + width - 1), max_y(y + height - 1)
{
    auto i= Visible::setXY().begin();
    i = Visible::setXY().erase(i);
    for(INT Y = y; Y <= max_y; ++Y) {
        for(INT X = x; X <= max_x; ++X) {
            Visible::setXY().push_back(Coordinates(X, Y));
        }
    }
}

void GameArea::show() const {
    for(auto i : Visible::getXY())
        std::cout << '[' << i.x << ',' << i.y << ']';
    std::cout.put('\n');
}

//
// VISIBLE.H
//
Visible * Visible::makeGameArea(INT x, INT y, INT w, INT h)
{
	return new GameArea(x, y, w, h);
}