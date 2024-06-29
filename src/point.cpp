#include "../headers/point.hpp"

Point::Point()
{
	x=0.0;
	y=0.0;
}

Point::Point(float x, float y){
	this->x = x;
	this->y = y;
}

float Point::getX(){
	return this->x;
}

float Point::getY(){
	return this->y;
}

Point Point::operator+(const Point& toAdd){
	return Point(this->x + toAdd.x, this->y + toAdd.y);
}

Point& Point::operator+=(const Point& other) {
        x += other.x;
        y += other.y;
        return *this;
}