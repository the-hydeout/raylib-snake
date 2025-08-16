#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H
#include <raylib.h>

class SnakeFood {
    private:
        Rectangle snake_food_cell {
            0.0f,
            0.0f,
            30.0f,
            30.0f,
        };
        int snake_food_pos_x {2};
        int snake_food_pos_y {5};

    public:
        void draw_snake_food();
        void is_food_eaten();
        void has_collided_with_snake(Rectangle rec1, Rectangle rec2);
        Rectangle get_food_cell();

};

#endif