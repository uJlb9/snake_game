#include <iostream>
#include "visible.h"

int main() {
	auto snake = Visible::makeSnake();  // new
	auto apple = Visible::makeApple(3, 2);
	auto game_area = Visible::makeGameArea(0, 0, 9, 11);
    game_area->show();

	return 0;
}