#include "../headers/gameModel.hpp"
#include <iostream>

GameModel::GameModel(): balls(){
	
	screenPixelWidth = screenDims.screenWidth;
	screenPixelHeight = screenDims.screenHeight;
	
	gamePixelWidth = (static_cast<float> (screenPixelWidth))/2.3;
	gamePixelHeight = static_cast<float> (screenDims.screenHeight);

	gameUpperLeft = Point((screenPixelWidth - gamePixelWidth)/2, 0);
	gameDownRight = Point((screenPixelWidth - gamePixelWidth)/2 + gamePixelWidth, gamePixelHeight);
	
	FPS = 160;
	bar = new Bar(ScreenCoords(screenDims.screenWidth/2-200/2, screenDims.screenHeight-10),
		RED, gamePixelWidth/3, 10, this->FPS);

	Ball::velocity = (5.0f*60)/this->FPS;

	balls.push_back(Ball(Point(gameUpperLeft.getX() + gamePixelWidth/2,
							 gameUpperLeft.getY() + gamePixelHeight/2)));

}

void GameModel::update(){
	// Update States

	// Update Positions
	bar->updatePosition(this->gameUpperLeft, this->gameDownRight);
	for(Ball &ball : balls){
		ball.updatePosition(this);
	}

	// Draw
	this->drawBackGround();
	bar->draw();
	for(Ball ball : balls){
		ball.draw();
	}
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

bool GameModel::willCollide(Ball * ball, Point& newPos){
	if(newPos.getX() < this->gameUpperLeft.getX()){ // Colliding with left wall
		ball->setDirection(Point(-ball->getDirection().getX(), ball->getDirection().getY()));
		return true;
	}
	if(newPos.getX() > this->gameDownRight.getX()){ // Colliding with right wall
		ball->setDirection(Point(-ball->getDirection().getX(), ball->getDirection().getY()));
		return true;
	}
	if(newPos.getY() < this->gameUpperLeft.getY()){ // Colliding with top wall
		ball->setDirection(Point(ball->getDirection().getX(), -ball->getDirection().getY()));
		return true;
	}
	if(newPos.getY() > this->gameDownRight.getY()){ // Colliding with bottom wall
		ball->setDirection(Point(ball->getDirection().getX(), -ball->getDirection().getY()));
		return true;
	}

	return false;
}
