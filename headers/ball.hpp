#ifndef BALL_HPP
#define BALL_HPP

#include "point.hpp"

class Ball{
	
	private:
	
	static float velocity;
	
	Point position;
	const int r = 3;

	public:

	Ball(Point p);

};

#endif