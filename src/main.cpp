#include <raylib.h>

int main(){
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Template");

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()){
        BeginDrawing();

            

        EndDrawing();
    }
}