#ifndef SNAKE_TYPEDEFS_H
#define SNAKE_TYPEDEFS_H

using INT = int;
using CHAR = char;
enum DIRECTION { left, right, up, down };
struct Pos {
    INT x, y;
};
using CONTAINER = std::list<Pos>;

#endif //SNAKE_TYPEDEFS_H