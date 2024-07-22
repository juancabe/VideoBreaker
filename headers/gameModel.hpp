#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include <vector>

#include "bar.hpp"
#include "ball.hpp"
#include "point.hpp"
#include "block.hpp"
#include "ppm.hpp"


class GameModel{

private:
	Bar * bar;

	unsigned int FPS;

	int actualLevel;
	int numLevels;
	bool * levelsSelected;
	
	int screenPixelWidth;
	int screenPixelHeight;
	float gamePixelWidth;
	float gamePixelHeight;

	Point gameUpperLeft;
	Point gameDownRight;

    std::vector<Ball> balls;
    std::vector<Block> blocks;

	void drawBackGround();
	void loadLevel(int level);


	void gameOver();
	bool isGameOver;
	bool isGameWon;

	void (*playPop)();

public:

	~GameModel();
	GameModel(void (*playPop)(), unsigned int FPS, int numLevels, bool * levelsSelected);
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