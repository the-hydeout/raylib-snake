#include <iostream> 
#include <raylib.h>
#include "classes/Snake/Snake.h"
#include <chrono>

const int screenWidth = 900;
const int screenHeight = 900;

void draw_grid();

int main() {

    InitWindow(screenWidth, screenHeight, "Snake");

    Snake player_snake;

    SetTargetFPS(60);
    
    float timer = 0.0f;
    float interval = .2f;
    
    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        timer += GetFrameTime();

        if(timer >= interval) {
            std::cout << "BOOM" << std::endl;
            timer = 0;
        }

        player_snake.draw_snake();
        player_snake.move_snake();
        player_snake.set_snake_direction();

        

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