#include "../headers/gameModel.hpp"
#include <iostream>

GameModel::GameModel(): balls(){

	isGameOver = false;
	
	screenPixelWidth = screenDims.screenWidth;
	screenPixelHeight = screenDims.screenHeight;
	
	gamePixelWidth = (static_cast<float> (screenPixelWidth))/2.3;
	gamePixelHeight = static_cast<float> (screenDims.screenHeight);

	gameUpperLeft = Point((screenPixelWidth - gamePixelWidth)/2, 0);
	gameDownRight = Point((screenPixelWidth - gamePixelWidth)/2 + gamePixelWidth, gamePixelHeight);
	
	FPS = 160;

	// Create bar
	bar = new Bar(ScreenCoords(screenDims.screenWidth/2-200/2, screenDims.screenHeight-40),
		RED, gamePixelWidth/3, 30, this->FPS);
	// Set static Ball class variable
	Ball::velocity = (5.0f*60)/this->FPS;
	// Create start ball
	balls.push_back(Ball(Point(gameUpperLeft.getX() + gamePixelWidth/2,
							 gameUpperLeft.getY() + gamePixelHeight/2)));

	// Create blocks
	for(int j = 10; j < 15;j++)
		for(int i = 0; i < (static_cast<int>(gamePixelWidth))/(Block::width + Block::margin); i++){
			blocks.push_back(Block(Point(gameUpperLeft.getX() + i*Block::width + i*Block::margin,
										gameUpperLeft.getY() + Block::height*j + Block::margin*j)));
		}
}

void GameModel::update(){

	// Update Positions
	bar->updatePosition(this->gameUpperLeft, this->gameDownRight);

	for(int i = 0; i < balls.size(); i++){
		if(balls[i].updatePosition(this)){
			balls.erase(balls.begin() + i);
		}
	}
	if(balls.size() == 0){
		gameOver();
	}

	// Draw
	this->drawBackGround();
	bar->draw();
	for(Ball ball : balls){
		ball.draw();
	}
	for(Block block : blocks){
		block.draw();
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
	if(newPos.getX() - ball->getR() < this->gameUpperLeft.getX()){ // Colliding with left wall
		ball->setDirection(Point(-ball->getDirection().getX(), ball->getDirection().getY()));
		return true;
	}
	if(newPos.getX() + ball->getR() > this->gameDownRight.getX()){ // Colliding with right wall
		ball->setDirection(Point(-ball->getDirection().getX(), ball->getDirection().getY()));
		return true;
	}
	if(newPos.getY() - ball->getR() < this->gameUpperLeft.getY()){ // Colliding with top wall
		ball->setDirection(Point(ball->getDirection().getX(), -ball->getDirection().getY()));
		return true;
	}
	for(int i = 0; i < blocks.size(); i++){
		if(blocks[i].ballCollision(ball, newPos)){
			blocks.erase(blocks.begin() + i);
		}
	}

	if(bar->ballCollision(ball, newPos)){ // colliding with bar
		return true;
	}
	/*
	if(newPos.getY() + ball->getR() > this->gameDownRight.getY()){ // Colliding with bottom wall
		ball->setDirection(Point(ball->getDirection().getX(), -ball->getDirection().getY()));
		return true;
	}
	*/

	return false;
}

Point * GameModel::getGameUpperLeft(){
	return &this->gameUpperLeft;
}

Point * GameModel::getGameDownRight(){
	return &this->gameDownRight;
}

void GameModel::gameOver(){
	std::cout << "Game Over" << std::endl;
	isGameOver = true;
	return;
}