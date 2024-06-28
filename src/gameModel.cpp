#include "../headers/gameModel.hpp"

GameModel::GameModel(){
	
	screenPixelWidth = screenDims.screenWidth;
	screenPixelHeight = screenDims.screenHeight;
	
	gamePixelWidth = (static_cast<float> (screenPixelWidth))/2.3;
	gamePixelHeight = static_cast<float> (screenDims.screenHeight);

	gameUpperLeft = Point((screenPixelWidth - gamePixelWidth)/2, 0);
	gameDownRight = Point((screenPixelWidth - gamePixelWidth)/2 + gamePixelWidth, gamePixelHeight);
	
	FPS = 60;
	bar = new Bar(ScreenCoords(screenDims.screenWidth/2-200/2, screenDims.screenHeight-10),
		RED, gamePixelWidth/3, 10, this->FPS);
}

void GameModel::update(){
	// Update States

	// Update Positions
	bar->updatePosition(this->gameUpperLeft, this->gameDownRight);

	// Draw
	bar->draw();
	DrawCircle(this->gameUpperLeft.getX(), this->gameUpperLeft.getY(), 5, RED);
	DrawCircle(this->gameDownRight.getX(), this->gameDownRight.getY(), 5, RED);
}

unsigned int GameModel::getFPS(){
	return this->FPS;
}

int GameModel::getScreenPixelHeight(){
	return this->screenPixelHeight;
}

int GameModel::getScreenPixelWidth(){
	return this->screenPixelWidth;
}