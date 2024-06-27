#include <raylib.h>
#include <iostream>
#include <string>
#include "../headers/bar.hpp"
#include "../headers/coords.hpp"
#include "../headers/gameModel.hpp"

int main(){

    InitWindow(screenDims.screenWidth, screenDims.screenHeight, "VideoBreaker");

    GameModel gm = GameModel();

    SetTargetFPS(gm.getFPS());

    // Main game loop
    while (!WindowShouldClose()){


        BeginDrawing();

            ClearBackground(BLACK);
            
            gm.update();


        EndDrawing();

    }
}