#include <raylib.h>
#include <string>
#include <iostream>
#include "../headers/gameModel.hpp"

typedef struct{
	bool * levelsSelected;
	int levels;
	unsigned int fps;
} menuSelector;

int numberOfLevels();

menuSelector menuScreen(){

	menuSelector ms;

	const int menuWidth = 800;
	const int menuHeight = 600;

	const int menuItems = 4;
	const int itemsPadding = menuHeight/(menuItems+1);
	const int textHeight = itemsPadding*2/3;
	
	unsigned int userFps = 60;

	int levels = numberOfLevels();
	bool * levelsSelected = new bool[levels]; 

	ms.levelsSelected = levelsSelected;
	ms.levels = levels;

	for(int i = 0; i < levels; i++){
		levelsSelected[i] = false;
	}

	InitWindow(menuWidth, menuHeight, "VideoBreaker");
	SetTargetFPS(60);

	while (!WindowShouldClose()){
		BeginDrawing();
			
			Vector2 mousePos = GetMousePosition();

			ClearBackground(BLACK);

			{	// FPS
				int padding = 10;
				int fpsStartTextWidth = MeasureText("FPS: ", textHeight);
				DrawText("FPS: ", menuWidth/7, itemsPadding*1, textHeight, WHITE);
				int minusSignTextWidth = MeasureText("-", textHeight);
				Rectangle minusFpsRec = {static_cast<float>(menuWidth/7) + fpsStartTextWidth,
										static_cast<float>(itemsPadding*1),
										static_cast<float>(textHeight) - padding,
										static_cast<float>(textHeight) - padding};
				

				if(CheckCollisionPointRec(mousePos, minusFpsRec) && userFps > 10){
					DrawRectangleLinesEx(minusFpsRec, 2, WHITE);
					DrawText("-", menuWidth/7 + fpsStartTextWidth + (textHeight/2 - padding/2 - minusSignTextWidth/2),
							itemsPadding*1, textHeight, WHITE);	
					if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
						userFps -= 5;
					}
				} else {
					DrawText("-", menuWidth/7 + fpsStartTextWidth + (textHeight/2 - padding/2 - minusSignTextWidth/2),
							itemsPadding*1, textHeight, RED);
					DrawRectangleLinesEx(minusFpsRec, 2, RED);
				}

				int fpsNumberTextWidth = MeasureText(std::to_string(userFps).c_str(), textHeight);
				
				int userFpsXPos = menuWidth/7 + fpsStartTextWidth + textHeight + padding;

				DrawText(std::to_string(userFps).c_str(), userFpsXPos,
						itemsPadding*1, textHeight, WHITE);
				

				Rectangle increaseFpsRec = {
					static_cast<float>(userFpsXPos + fpsNumberTextWidth + padding*2),
					static_cast<float>(itemsPadding*1),
					static_cast<float>(textHeight) - padding,
					static_cast<float>(textHeight) - padding
				};

				if(CheckCollisionPointRec(mousePos, increaseFpsRec) && userFps < 360){
					DrawRectangleLinesEx(increaseFpsRec, 2, WHITE);
					DrawText("+", increaseFpsRec.x + (textHeight/2 - padding - minusSignTextWidth/2 + minusSignTextWidth/15),
							itemsPadding*1, textHeight, WHITE);
					if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
						userFps += 10;
					}
				} else {
					DrawText("+", increaseFpsRec.x + (textHeight/2 - padding - minusSignTextWidth/2 + minusSignTextWidth/15),
							itemsPadding*1, textHeight, RED);
					DrawRectangleLinesEx(increaseFpsRec, 2, RED);
				}

				ms.fps = userFps;
				
			}

			{	// LEVEL SELECTOR
				int padding = 10;
				int levelTextWidth = MeasureText("SELECT LEVELS", textHeight);
				Rectangle selectLevel = {static_cast<float>(menuWidth/2) - static_cast<float>(levelTextWidth/2) - padding,
										static_cast<float>(itemsPadding*2),
										static_cast<float>(levelTextWidth) + padding*2,
										static_cast<float>(textHeight)};
				if(CheckCollisionPointRec(mousePos, selectLevel)){
					DrawRectangleLinesEx(selectLevel, 2, WHITE);
					DrawText("SELECT LEVELS", selectLevel.x + padding, selectLevel.y, textHeight, WHITE);
					if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){ // LEVEL SELECTING SCREEN
						EndDrawing();
						{
							int levelsItems = levels + 2;
							int levelsPadding = menuHeight/(levelsItems);
							int textHeight = levelsPadding*2/3;

							const char levelsText[] = "SELECT LEVELS";

							while(!IsKeyPressed(KEY_B)){
								if(WindowShouldClose()){
									CloseWindow();
									return ms;
								}

								Vector2 mousePos = GetMousePosition();
								BeginDrawing();

									ClearBackground(BLACK);

									int titleWidth = MeasureText(levelsText, static_cast<int>(static_cast<float>(textHeight)*1.3f));

									DrawText(levelsText, menuWidth/2 - titleWidth/2, levelsPadding, static_cast<int>(static_cast<float>(textHeight)*1.3f), GREEN);

									if(!levels)
										DrawText("No levels found", menuWidth/2 - MeasureText("No levels found", textHeight)/2, levelsPadding*2, textHeight, RED);
									else{
										for(int i = 0; i < levels; i++){
											Rectangle recSelector = {static_cast<float>(textHeight),
															static_cast<float>(levelsPadding*(i+2)),
															static_cast<float>(textHeight),
															static_cast<float>(textHeight)};

											if(CheckCollisionPointRec(mousePos, recSelector)){
												DrawRectangleLinesEx(recSelector, 2, WHITE);
												if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
													levelsSelected[i] = !levelsSelected[i];
											} else {
												DrawRectangleLinesEx(recSelector, 2, RED);
											}

											if(levelsSelected[i]){
												DrawText("X", recSelector.x + textHeight/5, recSelector.y, textHeight, GREEN);
											}

											DrawText(("Level " + std::to_string(i)).c_str(), recSelector.x + textHeight + 10, recSelector.y, textHeight, WHITE);											

										}
									}

									Rectangle backRec = {static_cast<float>(menuWidth - MeasureText("Back", textHeight) - MeasureText("Back", textHeight)/5 - textHeight),
														static_cast<float>(levelsPadding*(levelsItems - 1)),
														static_cast<float>(MeasureText("Back", textHeight) + MeasureText("Back", textHeight)/5*2),
														static_cast<float>(textHeight)};

									if(CheckCollisionPointRec(mousePos, backRec)){
										DrawRectangleLinesEx(backRec, 2, WHITE);
										DrawText("Back", backRec.x + MeasureText("Back", textHeight)/5, backRec.y, textHeight, WHITE);
										if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
											EndDrawing();
											break;
										}
									} else {
										DrawRectangleLinesEx(backRec, 2, RED);
										DrawText("Back", backRec.x + MeasureText("Back", textHeight)/5, backRec.y, textHeight, RED);
									}
									
									
								EndDrawing();
							}
						}
					} else{

					}
				} else {
					DrawRectangleLinesEx(selectLevel, 2, RED);
					DrawText("SELECT LEVELS", selectLevel.x + padding, selectLevel.y, textHeight, RED);
				}
			}

			// START
			{	
				int padding = 10;
				int startTextWidth = MeasureText("Start", textHeight);
				Rectangle startRec = {static_cast<float>(menuWidth/2) - static_cast<float>(startTextWidth/2) - padding,
									static_cast<float>(itemsPadding*menuItems - padding),
									static_cast<float>(startTextWidth + padding*2),
									static_cast<float>(textHeight + padding*2)};


				if(CheckCollisionPointRec(mousePos, startRec)){
					DrawRectangleLinesEx(startRec, 2, WHITE);
					DrawText("Start", startRec.x + padding, startRec.y + padding, textHeight, WHITE);
					if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
						CloseWindow();
						return ms;
					}
				} else {
					DrawRectangleLinesEx(startRec, 2, RED);
					DrawText("Start", startRec.x + padding, startRec.y + padding, textHeight, RED);
				}
			}

		EndDrawing();
	}

	CloseWindow();

	return ms;

}

int numberOfLevels(){
	if(DirectoryExists("levels")){
		int levels = 0;
		while(FileExists(("levels/level" + std::to_string(levels) + ".ppm").c_str())){
			levels++;
		}
		return levels;
	} else {
		return 0;
	}		
}

void gameWonScreen(GameModel& gm, void (*playPop)(), menuSelector ms)
{
    DrawText("You Won", gm.getScreenPixelWidth()/2 - 50, gm.getScreenPixelHeight()/2, 20, WHITE);
    DrawText("Press Enter to restart", gm.getScreenPixelWidth()/2 - 100, gm.getScreenPixelHeight()/2 + 20, 20, WHITE);
    if(IsKeyPressed(KEY_ENTER)){
        gm = GameModel(playPop, ms.fps, ms.levels, ms.levelsSelected);
    }
}

void gameOverScreen(GameModel& gm, void (*playPop)(), menuSelector ms){
    DrawText("Game Over", gm.getScreenPixelWidth()/2 - 50, gm.getScreenPixelHeight()/2, 20, WHITE);
    DrawText("Press Enter to restart", gm.getScreenPixelWidth()/2 - 100, gm.getScreenPixelHeight()/2 + 20, 20, WHITE);
    if(IsKeyPressed(KEY_ENTER)){
        gm = GameModel(playPop, ms.fps, ms.levels, ms.levelsSelected);
    }
}