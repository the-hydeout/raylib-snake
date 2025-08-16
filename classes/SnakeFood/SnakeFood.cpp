#include "SnakeFood.h"
#include <iostream>

// https://stackoverflow.com/questions/12657962/how-do-i-generate-a-random-number-between-two-variables-that-i-have-stored
//make sure to include the random number generators and such
#include <random>
//the random device that will seed the generator
std::random_device seeder;
//then make a mersenne twister engine
std::mt19937 engine(seeder());
//then the easy part... the distribution
std::uniform_int_distribution<int> dist(1, 30); // min/max
//then just generate the integer like this:
int compGuess = dist(engine);
int randNum_x = rand()%(30-1 + 1) + 1;
int randNum_y = rand()%(30-1 + 1) + 1;

void SnakeFood::draw_snake_food() {
        DrawRectanglePro
        (
            snake_food_cell, 
            { -static_cast<float>(randNum_x * 30), -static_cast<float>(randNum_y * 30)}, 
            0.0f, 
            WHITE
        );
        // std::cout << randNum << std::endl;
}

void SnakeFood::has_collided_with_snake(Rectangle rec1, Rectangle rec2) {
    if(CheckCollisionRecs(rec1, rec2)) {
        randNum_x = rand()%(30-1 + 1) + 1;
        randNum_y = rand()%(30-1 + 1) + 1;
        // std::cout << "collided with snake" << std::endl;
    }
}

Rectangle SnakeFood::get_food_cell() {
    return snake_food_cell;
}