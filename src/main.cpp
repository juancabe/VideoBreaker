#include <raylib.h>
#include <iostream>
#include <string>
#include "menu.cpp"
#include "../headers/bar.hpp"
#include "../headers/coords.hpp"
#include "../headers/gameModel.hpp"

Sound pop;

void playPop();

int main(){

    menuSelector ms = menuScreen();

    GameModel gm = GameModel(&playPop, ms.fps, ms.levels, ms.levelsSelected);
    std::cout << "isGameWon: " << gm.getIsGameWon() << std::endl;
    std::cout << "isGameOver: " << gm.getIsGameOver() << std::endl;
    InitWindow(gm.getScreenPixelWidth(), gm.getScreenPixelHeight(), "VideoBreaker");
    InitAudioDevice();
    pop = LoadSound("resources/audio/pop.wav");
    
    SetSoundVolume(pop, 0.1f);

    SetTargetFPS(gm.getFPS());
    

    // Main game loop
    while (!WindowShouldClose()){


        BeginDrawing();

            ClearBackground(BLACK);

            if(gm.getIsGameOver())
                gameOverScreen(gm, &playPop, ms);
            else if(gm.getIsGameWon()){
                ms = gameWonScreen(gm, &playPop);
                if(ms.levelsSelected){
                    BeginDrawing();
                }
            }
            else
                gm.update();
            
            
            // Draw FPS
            DrawText(std::to_string(GetFPS()).c_str(), 10, 10, 20, WHITE);


        EndDrawing();

    }
}

void playPop(){
    PlaySound(pop);
}

