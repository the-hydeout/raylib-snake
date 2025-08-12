#include <iostream> 
#include <raylib.h>


const int screenWidth = 900;
const int screenHeight = 900;


void draw_center_lines();

int main() {

    InitWindow(screenWidth, screenHeight, "Snake");

     while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        draw_center_lines();

        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}


// to help with positioning / centering of objects
void draw_center_lines() {
    DrawLine(
        0, // x start pos
        screenHeight/2, // y start pos
        screenWidth, //x end pos
        screenHeight/2, // y end pos
        WHITE
    );

    DrawLine(
        screenWidth/2, // x start pos
        0, // y start pos
        screenWidth/2, //x end pos
        screenHeight, // y end pos
        WHITE
    );
}