#ifndef SNAKE_TYPEDEFS_H
#define SNAKE_TYPEDEFS_H

#include <cstring>

using INT = int;
using CHAR = char;
enum Direction { left = -100, right = 100, up = 200, down = -200 };
enum Type { t_field, t_snake, t_apple };

struct Conditions {
    explicit Conditions(const char *statuses) : arr() { strcpy(arr, statuses); }
    CHAR arr[3]; // 0 - normal, 1 - hidden, 2 - dead
};

static const char *conditions_field{"..."};
static const char *conditions_snake{"o,x"};
static const char *conditions_apple{"Aaa"};

const INT STANDS_STILL      {0};
const INT HIDDEN            {1};
const INT DEAD              {2};
const INT DELETE            {9};
const INT MOVING_LEFT       {-100};
const INT MOVING_RIGHT      {100};
const INT MOVING_UP         {200};
const INT MOVING_DOWN       {-200};

struct Coordinates {
    INT x, y;
};

class GameObject;

using CONTAINER_COORDINATES = std::list<Coordinates>;
using CONTAINER_VISIBLE = std::list<GameObject *>;

#endif //SNAKE_TYPEDEFS_H