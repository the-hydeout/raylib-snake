#include <iostream> 
#include <raylib.h>
#include "classes/Snake/Snake.h"

const int screenWidth = 900;
const int screenHeight = 900;

void draw_grid();

int main() {

    InitWindow(screenWidth, screenHeight, "Snake");

    Snake player_snake;

    SetTargetFPS(8);

    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        player_snake.draw_snake();
        player_snake.move_snake();

        

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