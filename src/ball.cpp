#include "../headers/ball.hpp"
#include "../headers/gameModel.hpp"
#include <iostream>

float Ball::velocity = 100000.0f;

Ball::Ball(Point p)
{
	this->position = p;
	this->direction = Point(1.0f, 1.0f);

}

void Ball::updatePosition(GameModel * gm){
	Point newPos = this->position + this->direction*velocity;

	gm->willCollide(this, newPos);
	this->position += (this->direction*velocity);
	
}

void Ball::draw(){
	Point ghostBall(this->position);
	for(int i = 0; i < 100; i++){
		ghostBall += (this->direction*10.0f);
		DrawCircle(ghostBall.getX(), ghostBall.getY(), 2, WHITE);
	}
	DrawCircle(position.getX(), position.getY(), this->r, RED);
}

Point Ball::getDirection(){
	return this->direction;
}

void Ball::setDirection(Point direction){
	this->direction = direction;
}

int Ball::getR(){
	return this->r;
}

Point Ball::getPos(){
	return this->position;
}