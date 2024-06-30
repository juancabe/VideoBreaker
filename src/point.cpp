#include "../headers/point.hpp"
#include <math.h>

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
Point Point::operator*(float factor) const {
	return Point(x * factor, y * factor);
}

Point& Point::operator*=(float factor) {
	x *= factor;
	y *= factor;
	return *this;
}

Point Point::operator-(const Point& toSub){
	return Point(this->x - toSub.x, this->y - toSub.y);
}

Point& Point::operator-=(const Point& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

void Point::normalizeToOne(){
	if(x == y){
		x = 1.0, y = 1.0;
		return;
	}
	if(abs(x) > abs(y)){
		float temp = y/x;
		int xSymbol = 1, ySymbol = 1;
		if(x < 0) xSymbol = -1;
		if(y < 0) ySymbol = -1;
		x = 1.0 * xSymbol;
		y = temp * ySymbol;
		return;
	}
	if(abs(y) > abs(x)){
		float temp = x/y;
		int xSymbol = 1, ySymbol = 1;
		if(x < 0) xSymbol = -1;
		if(y < 0) ySymbol = -1;
		y = 1.0 * ySymbol;
		x = temp * xSymbol;
		return;
	}
}