#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include <vector>

#include "bar.hpp"
#include "ball.hpp"
#include "point.hpp"
#include "block.hpp"


class GameModel{

private:
	Bar * bar;

	unsigned int FPS;

	
	int screenPixelWidth;
	int screenPixelHeight;
	float gamePixelWidth;
	float gamePixelHeight;

	Point gameUpperLeft;
	Point gameDownRight;

    std::vector<Ball> balls;
    std::vector<Block> blocks;

	void drawBackGround();
	void gameOver();
	bool isGameOver;
	bool isGameWon;

	void (*playPop)();

public:

	GameModel(void (*playPop)());
	void update();
	unsigned int getFPS();

	int getScreenPixelWidth();
	int getScreenPixelHeight();

	bool getIsGameOver();
	bool getIsGameWon();

    bool willCollide(Ball * ball, Point& newPos);


	Point * getGameUpperLeft();
	Point * getGameDownRight();

};

#endif