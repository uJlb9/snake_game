#include "game_object.h"
#include "calculate_scene.h"
#include "ascii_render.h"

int main() {
    GameField field;
    CONTAINER_GAME_OBJECTS scene;
    auto snake = GameObject::makeSnake();
    
    scene.push_back(snake);
    scene.push_back(GameObject::makeApple(6, 3));
    
    Data data(field, scene);
    AsciiRenderer ascii(data);
    
    data.calculate();
    ascii.render();
    
    snake->move(right);
    data.calculate();
    ascii.render();
    
    snake->move(right);
    data.calculate();
    ascii.render();
    
    snake->move(down);
    data.calculate();
    ascii.render();
    
    snake->move(down);
    data.calculate();
    ascii.render();
    
    snake->move(down);
    data.calculate();
    ascii.render();
    
    snake->move(right);
    data.calculate();
    ascii.render();
    
    snake->move(right);
    data.calculate();
    ascii.render();
    
    snake->move(right);
    data.calculate();
    ascii.render();
    
    snake->move(right);
    data.calculate();
    ascii.render();
    
    snake->move(up);
    data.calculate();
    ascii.render();
    
    snake->move(left);
    data.calculate();
    ascii.render();
    
    snake->move(down);
    data.calculate();
    ascii.render();
    
    data.calculate();
    ascii.render();

    return 0;
}