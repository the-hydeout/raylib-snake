#include "Snake.h"
#include <iostream>

void Snake::draw_snake() {
        DrawRectanglePro
        (
            snake_cell, 
            { -static_cast<float>(snake_pos_x * 30), -static_cast<float>(snake_pos_y * 30)}, 
            0.0f, 
            WHITE
        );
}

void Snake::move_snake() {
    snake_pos_x += 1;
}