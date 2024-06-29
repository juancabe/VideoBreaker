#ifndef POINT_HPP
#define POINT_HPP

class Point
{
private:
	float x;
	float y;
public:
	Point();
	Point(float x, float y);

	float getX();
	float getY();

	Point operator+(const Point& toAdd);
	Point& operator+=(const Point& other);
};


#endif