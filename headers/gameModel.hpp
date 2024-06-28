#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include <list>

#include "bar.hpp"
#include "ball.hpp"
#include "point.hpp"

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

	void drawBackGround();

public:
	GameModel();
	void update();
	unsigned int getFPS();

	int getScreenPixelWidth();
	int getScreenPixelHeight();

};

#endif