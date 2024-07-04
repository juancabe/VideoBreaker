#ifndef BALL_HPP
#define BALL_HPP

#include <raylib.h>
#include "point.hpp"

class GameModel;

class Ball{
	
	private:
	
	bool initial;
	
	Point direction;
	Point position;
	int r = 5;

	public:
	
	static float velocity;

	Ball(Point p, bool initial = false);
	Ball(float x, float y, bool initial = false);
	bool updatePosition(GameModel * gm);
	void draw();

	Point getDirection();
	void setDirection(Point direction);
	bool getInitial();
	
	int getR();

	Point getPos();


};

#endif