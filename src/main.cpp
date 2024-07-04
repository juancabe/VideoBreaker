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
            if(gm.getIsGameOver()){
                DrawText("Game Over", gm.getScreenPixelWidth()/2 - 50, gm.getScreenPixelHeight()/2, 20, WHITE);
                DrawText("Press Enter to restart", gm.getScreenPixelWidth()/2 - 100, gm.getScreenPixelHeight()/2 + 20, 20, WHITE);
                if(IsKeyPressed(KEY_ENTER)){
                    gm = GameModel();
                }
            } else if(gm.getIsGameWon()){
                DrawText("You Won", gm.getScreenPixelWidth()/2 - 50, gm.getScreenPixelHeight()/2, 20, WHITE);
                DrawText("Press Enter to restart", gm.getScreenPixelWidth()/2 - 100, gm.getScreenPixelHeight()/2 + 20, 20, WHITE);
                if(IsKeyPressed(KEY_ENTER)){
                    gm = GameModel();
                }
            }
            else{
                gm.update();
            }
            


        EndDrawing();

    }
}