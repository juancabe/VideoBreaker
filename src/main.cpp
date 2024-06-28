#include <raylib.h>
#include <iostream>
#include <string>
#include "../headers/bar.hpp"
#include "../headers/coords.hpp"
#include "../headers/gameModel.hpp"

int main(){

    GameModel gm = GameModel();

    InitWindow(gm.getScreenPixelWidth(), gm.getScreenPixelHeight(), "VideoBreaker");

    SetTargetFPS(gm.getFPS());

    // Main game loop
    while (!WindowShouldClose()){


        BeginDrawing();

            ClearBackground(BLACK);
            
            gm.update();


        EndDrawing();

    }
}