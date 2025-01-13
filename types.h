#ifndef SNAKE_TYPES_H
#define SNAKE_TYPES_H

#include <cstring>

using INT = int;
using CHAR = char;
enum Direction { left = -100, right = 100, up = 200, down = -200 };
enum Type { t_field, t_snake, t_apple };

struct Conditions {
    explicit Conditions(const char *statuses) : arr() { strcpy(arr, statuses); }
    CHAR arr[32]; // 0 - normal, 1 - hidden, 2 - dead
};

const INT STANDS_STILL      {0};
const INT HIDDEN            {1};
const INT DEAD              {2};
const INT MOVING_LEFT       {3};
const INT MOVING_RIGHT      {4};
const INT MOVING_UP         {5};
const INT MOVING_DOWN       {6};
const INT DELETE            {9};

struct Segment {
    INT x, y;
    bool operator==(const Segment &other) const { return (x == other.x && y == other.y); }
};

class GameObject;

using CONTAINER_BODY = std::vector<Segment>;
using CONTAINER_GAME_OBJECTS = std::list<GameObject *>;

#endif //SNAKE_TYPES_H