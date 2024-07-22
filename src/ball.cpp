#include "../headers/ball.hpp"
#include "../headers/gameModel.hpp"
#include <iostream>
#include <random>

float Ball::velocity = 100000.0f;

Ball::Ball(Point p, bool initial): position(p), initial(initial) {
	if(initial == true){
		this->direction = Point(0.1f, 1.0f);
	} else{
		float xRand = (rand()%2000 - 1000)/1000.0f;
		this->direction = Point(xRand, 1.0f);
	}
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

	DrawCircle(position.getX(), position.getY(), this->r, initial?RED:WHITE);

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


bool Ball::getInitial(){
	return this->initial;
}