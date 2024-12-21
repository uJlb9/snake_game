#ifndef SNAKE_TYPEDEFS_H
#define SNAKE_TYPEDEFS_H

using INT = int;
using CHAR = char;
enum DIRECTION { left, right, up, down };

struct Coordinates {
    INT x, y;
};
using CONTAINER_COORDINATES = std::list<Coordinates>;

class Visible;
using CONTAINER_VISIBLE = std::list<Visible *>;

#endif //SNAKE_TYPEDEFS_H