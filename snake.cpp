#include "visible.h"

class Snake : public Visible {
public:
	explicit Snake(INT size = D_SNAKE_SIZE, INT x = 0, INT y = 0);
	void move(DIRECTION dir) override;
private:
	INT size_; // snake's length
	DIRECTION dir_;
};


Snake::Snake(INT size, INT x, INT y)
    : Visible('S', x, y), size_(size), body(), dir_(right)
{
	for(INT i = 0; i != size_; ++i)
		body.emplace_back(Pos(x - i, y));
}


void Snake::move(DIRECTION dir)
{
    if(dir_ == dir)
        return;
    dir_ = dir;
	
}


//
// VISIBLE.H
//
Visible * Visible::makeSnake(INT, INT, INT)
{
	return new Snake;
}