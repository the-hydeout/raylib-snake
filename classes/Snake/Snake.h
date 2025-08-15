#ifndef SNAKE_H
#define SNAKE_H
#include <raylib.h>
#include <string>

class Snake {
    private:
        Rectangle snake_cell {
            0.0f,
            0.0f,
            30.0f,
            30.0f,
        };
        int snake_length {1};
        int snake_pos_x {1};
        int snake_pos_y {3};
        KeyboardKey key_pressed {KEY_DOWN};

    public:
        void draw_snake();
        void move_snake();
        KeyboardKey get_snake_direction();
        void set_snake_direction();
};

#endif