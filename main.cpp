#include <iostream>
#include "visible.h"

int main() {
	std::vector<Visible *> Scene;
    Scene.push_back(Visible::makeGameArea(0, 0, 7, 9));
    Scene.push_back(Visible::makeSnake());

	return 0;
}