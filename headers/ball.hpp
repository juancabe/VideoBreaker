#ifndef BALL_HPP
#define BALL_HPP

#include <raylib.h>
#include "point.hpp"

class GameModel;

class Ball{
	
	private:
	
	static float velocity;
	
	Point direction;
	Point position;
	const int r = 3;

	public:

	Ball(Point p);
	void updatePosition(GameModel * gm);
	void draw();

	Point getDirection();
	void setDirection(Point direction);


};

#endif