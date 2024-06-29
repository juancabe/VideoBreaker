#ifndef BALL_HPP
#define BALL_HPP

#include <raylib.h>
#include "point.hpp"

class GameModel;

class Ball{
	
	private:
	
	
	Point direction;
	Point position;
	const int r = 3;

	public:
	
	static float velocity;

	Ball(Point p);
	void updatePosition(GameModel * gm);
	void draw();

	Point getDirection();
	void setDirection(Point direction);


};

#endif