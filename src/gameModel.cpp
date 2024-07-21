#include "../headers/gameModel.hpp"
#include <iostream>
#include <random>
#include <algorithm>

void GameModel::loadLevel(int level){
	ppm pixels = ppm(("levels/level" + std::to_string(level) + ".ppm").c_str());
	unsigned char ** pixelsMem = pixels.getPixels();

	Block::width = gamePixelWidth/pixels.getWidth() - Block::margin;
	Block::height = Block::width;

	for(int i = 0; i < pixels.getHeight(); i++){
		for(int j = 0; j < pixels.getWidth()*3; j += 3){
			if(pixelsMem[i][j] == 255 && pixelsMem[i][j+1] == 255 && pixelsMem[i][j+2] == 255){
				continue;
			} else if(pixelsMem[i][j] == 0 && pixelsMem[i][j+1] == 0 && pixelsMem[i][j+2] == 0){
				blocks.push_back(Block(Point(gameUpperLeft.getX() + j/3*Block::width + j/3*Block::margin,
										gameUpperLeft.getY() + Block::height*i + Block::margin*i)));
			} else {
				blocks.push_back(Block(Point(gameUpperLeft.getX() + j/3*Block::width + j/3*Block::margin,
										gameUpperLeft.getY() + Block::height*i + Block::margin*i), true));
			}
		}
	}
}

GameModel::GameModel(void (*playPop)(), unsigned int FPS, int numLevels, bool * levelsSelected):
balls(), playPop(playPop), FPS(FPS), blocks()
{


	actualLevel = -1;
	this->numLevels = numLevels;
	this->levelsSelected = new bool[numLevels];

	for(int i = numLevels - 1; i >= 0; i--){
		this->levelsSelected[i] = levelsSelected[i];
		if(levelsSelected[i]){
			actualLevel = i;
		}
	}


	isGameOver = false;
	if(actualLevel == -1){
		isGameWon = true;
		return;
	}
	else
		isGameWon = false;
	
	screenPixelWidth = screenDims.screenWidth;
	screenPixelHeight = screenDims.screenHeight;
	
	gamePixelWidth = (static_cast<float> (screenPixelWidth))/2.3;
	gamePixelHeight = static_cast<float> (screenDims.screenHeight);

	gameUpperLeft = Point((screenPixelWidth - gamePixelWidth)/2, 0);
	gameDownRight = Point((screenPixelWidth - gamePixelWidth)/2 + gamePixelWidth, gamePixelHeight);
	
	this->FPS = FPS;

	// Create bar
	bar = new Bar(ScreenCoords(screenDims.screenWidth/2-200/2, screenDims.screenHeight-40),
		RED, gamePixelWidth/3, 30, this->FPS);
	// Set static Ball class variable
	Ball::velocity = (5.0f*60)/this->FPS;
	// Create start ball
	balls.push_back(Ball(Point(gameUpperLeft.getX() + gamePixelWidth/2,
							 gameUpperLeft.getY() + gamePixelHeight/2), true));

	// Create blocks

	loadLevel(actualLevel);

}


void GameModel::update(){


	if(blocks.size() == 0){
		for(int i = actualLevel + 1; i < numLevels; i++){
			if(levelsSelected[i]){
				actualLevel = i;
				loadLevel(actualLevel);
				return;
			}
		}

		isGameWon = true;
		return;
	}

	// Update Positions

	std::vector<int> toDelete;

	for(int i = 0; i < balls.size(); i++){
		if(balls[i].updatePosition(this)){
			toDelete.push_back(i);
		}
	}

	std::sort(toDelete.begin(), toDelete.end());
	for(int i = 0; i < toDelete.size(); i++){
		balls.erase(balls.begin() + toDelete[i] - i);
	}

	bar->updatePosition(this->gameUpperLeft, this->gameDownRight);
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

bool GameModel::getIsGameOver(){
	return this->isGameOver;
}

bool GameModel::getIsGameWon(){
	return this->isGameWon;
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
			if(blocks[i].getSpawnsBall())
				balls.push_back(
					Ball(Point(blocks[i].getUpLeftPos().getX() + Block::width/2,
							   blocks[i].getUpLeftPos().getY() + Block::height+ball->getR()), false));
			blocks.erase(blocks.begin() + i);
			playPop();
			return true;
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
	isGameOver = true;
	return;
}