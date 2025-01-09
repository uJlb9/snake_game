#include "game_object.h"
#include "calculate_scene.h"
#include "ascii_render.h"

int main() {
    CONTAINER_GAME_OBJECTS scene;
    auto field = GameObject::makeGameArea();
    auto snake = GameObject::makeSnake();
    
    scene.push_back(field);
    scene.push_back(snake);
    scene.push_back(GameObject::makeApple(6, 3));
    
    Data data(scene);
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
    
    
    return 0;
}