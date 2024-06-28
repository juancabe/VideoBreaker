#include "../headers/gameModel.hpp"
#include <iostream>

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
	this->drawBackGround();
	bar->draw();
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

void GameModel::drawBackGround(){

	static Rectangle rec = {
		this->gameUpperLeft.getX(),
		this->gameUpperLeft.getY(),
		this->gamePixelWidth,
		this->gamePixelHeight
	};

	static Color cGy = {65, 65, 65, 100};
	static Color dGy = {30, 30, 30, 100};

	DrawRectangleGradientEx(rec, dGy, cGy, dGy, cGy);
}
