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
    if(IsKeyDown(KEY_DOWN)) {
        snake_pos_y += 1;
    } else if (IsKeyDown(KEY_UP)) {
        snake_pos_y -= 1;
    } else if (IsKeyDown(KEY_LEFT)) {
        snake_pos_x -= 1;
    } else if (IsKeyDown(KEY_RIGHT)) {
        snake_pos_x += 1;
    }
    
}