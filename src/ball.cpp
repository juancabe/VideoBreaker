#include "../headers/ball.hpp"
#include "../headers/gameModel.hpp"
#include <iostream>

float Ball::velocity = 100000.0f;

Ball::Ball(Point p)
{
	this->position = p;
	this->direction = Point(0.1f, 1.0f);

}

bool Ball::updatePosition(GameModel * gm){
	Point newPos = this->position + this->direction*velocity;

	gm->willCollide(this, newPos);
	this->position += (this->direction*velocity);

	if(this->position.getY() - this->r > gm->getGameDownRight()->getY()){
		return true;
	}else{
		return false;
	}
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

Ball& Ball::operator=(const Ball& other) {
    // Copy each member variable from `other` to `this`
    this->position = other.position;
    // Repeat for other member variables...

    return *this; // Return a reference to the current instance
}