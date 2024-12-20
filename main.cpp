#include "visible.h"

int main() {
    std::list<Visible *> scene;
    auto field = Visible::makeGameArea(0, 0, 5, 7);
    auto snake = Visible::makeSnake();
    
    scene.push_back(field);
    scene.push_back(snake);
    
    
    
    delete snake;
    delete field;
    return 0;
}