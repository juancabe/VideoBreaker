#include <raylib.h>
#include <iostream>
#include <string>
#include "../headers/bar.hpp"
#include "../headers/coords.hpp"
#include "../headers/gameModel.hpp"

Sound pop;

void gameOverScreen(GameModel& gm);
void gameWonScreen(GameModel& gm);
void playPop();

int main(){

    GameModel gm = GameModel(&playPop);
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
                gameOverScreen(gm);
            else if(gm.getIsGameWon())
                gameWonScreen(gm);
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

void gameWonScreen(GameModel& gm)
{
    DrawText("You Won", gm.getScreenPixelWidth()/2 - 50, gm.getScreenPixelHeight()/2, 20, WHITE);
    DrawText("Press Enter to restart", gm.getScreenPixelWidth()/2 - 100, gm.getScreenPixelHeight()/2 + 20, 20, WHITE);
    if(IsKeyPressed(KEY_ENTER)){
        gm = GameModel(&playPop);
    }
}

void gameOverScreen(GameModel& gm){
    DrawText("Game Over", gm.getScreenPixelWidth()/2 - 50, gm.getScreenPixelHeight()/2, 20, WHITE);
    DrawText("Press Enter to restart", gm.getScreenPixelWidth()/2 - 100, gm.getScreenPixelHeight()/2 + 20, 20, WHITE);
    if(IsKeyPressed(KEY_ENTER)){
        gm = GameModel(&playPop);
    }
}