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
    if (x == y) {
        x = y = (x < 0) ? -1.0 : 1.0;
        return;
    }
    if (abs(x) > abs(y)) {
        float temp = y / abs(x);
        x = (x < 0) ? -1.0 : 1.0;
        y = temp * x;
        return;
    }
    if (abs(y) > abs(x)) {
        float temp = x / abs(y);
        y = (y < 0) ? -1.0 : 1.0;
        x = temp * y;
        return;
    }
}

