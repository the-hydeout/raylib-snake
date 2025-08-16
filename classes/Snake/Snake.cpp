#include "Snake.h"
#include <iostream>

void Snake::draw_snake() {
        DrawRectanglePro
        (
            snake_cell, 
            // { -static_cast<float>(snake_pos_x * 30), -static_cast<float>(snake_pos_y * 30)}, 
            {0, 0}, 
            0.0f, 
            WHITE
        );
}

KeyboardKey Snake::get_snake_direction() {
    return key_pressed;
}

void Snake::set_snake_direction() {
    if(IsKeyPressed(KEY_DOWN)) {
        key_pressed = KEY_DOWN;
    } else if (IsKeyPressed(KEY_UP)) {
        key_pressed = KEY_UP;
    } else if (IsKeyPressed(KEY_LEFT)) {
        key_pressed = KEY_LEFT;
    } else if (IsKeyPressed(KEY_RIGHT)) {
        key_pressed = KEY_RIGHT;
    }
}

void Snake::move_snake() {
    KeyboardKey curr_direction = get_snake_direction();
    switch(curr_direction) {
        case KEY_DOWN:
        snake_pos_y+=1;
        break;

        case KEY_UP:
        snake_pos_y-=1;
        break;

        case KEY_LEFT:
        snake_pos_x-=1;
        break;

        case KEY_RIGHT:
        snake_pos_x+=1;
        break;
    }
}

Rectangle Snake::get_snake_cell() {
    return snake_cell;
}