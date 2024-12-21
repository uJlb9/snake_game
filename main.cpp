#include "visible.h"
#include "ascii_render.h"

int main() {
    CONTAINER_VISIBLE scene;
    auto field = Visible::makeGameArea(0, 0, 7, 9);
    auto snake = Visible::makeSnake(3, 3, 3);
    auto apple = Visible::makeApple(6, 6);
    
    scene.push_back(field);
    scene.push_back(snake);
    scene.push_back(apple);
    
    AsciiRenderer ascii_renderer(scene);
    ascii_renderer.calculate();
    ascii_renderer.render();
    
    delete apple;
    delete snake;
    delete field;
    return 0;
}