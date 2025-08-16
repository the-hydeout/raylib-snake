#include <iostream> 
#include <raylib.h>
#include "classes/Snake/Snake.h"
#include "classes/SnakeFood/SnakeFood.h"
#include <chrono>

const int screenWidth = 900;
const int screenHeight = 900;

void draw_grid();

int main() {

    InitWindow(screenWidth, screenHeight, "Snake");

    Snake player_snake;
    
    SnakeFood player_food;

    SetTargetFPS(30);
    
    float timer = 0.0f;
    float interval = .2f;
    
    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        timer += GetFrameTime();

        if(timer >= interval) {
            // std::cout << "BOOM" << std::endl;
            timer = 0;
        }

        player_snake.draw_snake();
        player_snake.move_snake();
        player_snake.set_snake_direction();
        
        player_food.draw_snake_food();
        // player_food.is_food_eaten();
        player_food.has_collided_with_snake(player_snake.get_snake_cell(), player_food.get_food_cell());
        std::cout << player_snake.get_snake_cell().x << std::endl;
        std::cout << player_snake.get_snake_cell().y << std::endl;

        

        draw_grid();


        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void draw_grid() {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            DrawRectangleLines(i * 30, j * 30, 30, 30, WHITE);
        }
    }
}

// TODO
// - ADD FOOD
// - ADD SNAKE GROWTH
// - ADD SCORE
// - ADD PAUSE FUNCTION
// - ADD RANDOM GENERATOR
// - USE RANDOM GENERATOR TO SPAWN SNAKE FOOD AT RANDOM POINTS
// - MAKE SURE SNAKE FOOD DOES NOT SPAWN DIRECTLY ON THE SNAKE ITSELF.