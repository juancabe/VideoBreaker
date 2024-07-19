#ifndef PPM_HPP
#define PPM_HPP

#include <raylib.h>

class ppm
{
private:
	int width;
	int height;
	int maxColor;
	unsigned char **pixels; // Max maxColor is 256

public:
	ppm(char filename[]);
	~ppm();

	int getWidth();
	int getHeight();
	int getMaxColor();

	void draw();
};

#endif