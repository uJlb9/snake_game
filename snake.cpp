#include "visible.h"

class Snake : public Visible {
public:
	explicit Snake(INT size = D_SNAKE_SIZE,
				   INT posX = D_SNAKE_X,
				   INT posY = D_SNAKE_Y);
	void show() const override;
	void move(direction dir) override;
private:
	INT size_; // snake's length
	struct Segment {
        explicit Segment(INT posX = 0, INT posY = 0) : posX_(posX), posY_(posY) {}
		INT posX_, posY_; // segment's position.
	};
	std::vector<Segment> body; // coordinates of entire snake. Head is [0]
    direction dir_;
};


Snake::Snake(INT size, INT posX, INT posY)
    : Visible('S', posX, posY), size_(size), body(), dir_(right)
{
	for(INT i = 0; i != size_; ++i)
		body.emplace_back(posX - i, posY);
}

void Snake::show() const // test
{
	auto i = body.begin();
	std::cout << 'S';
	for( ; i != body.end(); ++i)
        std::cout << '[' << i->posX_ << ',' << i->posY_ << ']';
	std::cout.put('\n');
}

void Snake::move(direction dir)
{
    if(dir_ == dir)
        return;
    dir_ = dir;
	Visible::move(dir_);
	Segment tmp = body[0]; // buffer
	body[0] = Segment(getX(), getY());
	auto i = body.begin();
	for(++i; i != body.end(); ++i)
		std::swap(*i, tmp);
}

//
// VISIBLE.H
//
Visible * Visible::makeSnake()
{
	return new Snake;
}