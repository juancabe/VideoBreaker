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
};


