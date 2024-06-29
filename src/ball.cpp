#include "../headers/ball.hpp"
#include "../headers/gameModel.hpp"
#include <iostream>

float Ball::velocity = 1.0f;

Ball::Ball(Point p)
{
	this->position = p;
	this->direction = Point(1.0f, 1.0f);

}

void Ball::updatePosition(GameModel * gm){
	Point newPos = this->position + this->direction*velocity;

	if(!gm->willCollide(this, newPos)){
		this->position += (this->direction*velocity);
	}
}

void Ball::draw(){
	DrawCircle(position.getX(), position.getY(), 3, RED);
}

Point Ball::getDirection(){
	return this->direction;
}

void Ball::setDirection(Point direction){
	this->direction = direction;
}