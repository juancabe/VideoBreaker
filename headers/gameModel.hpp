#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include <vector>

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

    std::vector<Ball> balls;

	void drawBackGround();

public:
	GameModel();
	void update();
	unsigned int getFPS();

	int getScreenPixelWidth();
	int getScreenPixelHeight();

    bool willCollide(Ball * ball, Point& newPos);

};

#endif