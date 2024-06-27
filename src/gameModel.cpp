#include "../headers/gameModel.hpp"

GameModel::GameModel(){
	bar = new Bar(ScreenCoords(screenDims.screenWidth/2-200/2, screenDims.screenHeight-10), RED, 200, 10);
	FPS = 60;
}

void GameModel::update(){
	// Update States

	// Update Positions
	bar->updatePosition(this->FPS);

	// Draw
	bar->draw();
}

unsigned int GameModel::getFPS(){
	return this->FPS;
}