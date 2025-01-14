#ifndef SNAKE_GAME_GAME_FIELD_H
#define SNAKE_GAME_GAME_FIELD_H

#include "types.h"
#include "defaults.h"
#include <cstring>

static const char symbol_field{ '.' };

class GameField {
public:
    explicit GameField(INT w = D_AREA_SIZE_X, INT h = D_AREA_SIZE_Y);
    ~GameField() { delete [] game_field; }
    INT getWidth() const { return width; }
    INT getHeight() const { return height; }
    CHAR *getField() const { return game_field; }
private:
    INT width, height;
    CHAR *game_field;
};

GameField::GameField(INT w, INT h)
    : width(w), height(h), game_field(new CHAR[width*height]{})
{
    memset(game_field, symbol_field, width*height*sizeof(CHAR));
}

#endif //SNAKE_GAME_GAME_FIELD_H