#include "visible.h"
#include "calculate_scene.h"
#include "ascii_render.h"

int main() {
    CONTAINER_VISIBLE scene;
    auto field = Visible::makeGameArea(0, 0, 7, 9);
    auto snake = Visible::makeSnake(3, 3, 4);
    auto apple = Visible::makeApple(6, 6);
    scene.push_back(field);
    scene.push_back(snake);
    scene.push_back(apple);
    
    Data data(scene);
    AsciiRenderer ascii(data);
    
    data.calculate();
    ascii.render();
    
    snake->move(right);
    apple->move(left);
    data.calculate();
    ascii.render();
    
    delete apple;
    delete snake;
    delete field;
    return 0;
}