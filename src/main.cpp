#include <raylib.h>
#include "../headers/bar.hpp"
#include "../headers/coords.hpp"


int main(){

    InitWindow(screenDims.screenWidth, screenDims.screenHeight, "VideoBreaker");

    SetTargetFPS(60);

    Bar bar(ScreenCoords(screenDims.screenWidth/2-200/2, screenDims.screenHeight-10), RED, 200, 10);

    // Main game loop
    while (!WindowShouldClose()){
        BeginDrawing();

        bar.draw();

        EndDrawing();
    }
}