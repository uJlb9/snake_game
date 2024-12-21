#ifndef SNAKE_TYPEDEFS_H
#define SNAKE_TYPEDEFS_H

using INT = int;
using CHAR = char;
enum DIRECTION { left = -1, right = 1, up = 10, down = -10 };

struct Coordinates {
    INT x, y;
};
using CONTAINER_COORDINATES = std::list<Coordinates>;

class Visible;
using CONTAINER_VISIBLE = std::list<Visible *>;

#endif //SNAKE_TYPEDEFS_H