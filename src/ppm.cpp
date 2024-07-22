#include "../headers/ppm.hpp"
#include <string.h>
#include <fstream>
#include <iostream>

ppm::ppm(const char filename[])
{
	pixels = nullptr;
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "Failed to open file: " << filename << std::endl;
		return;
	}

	// Read the PPM header
	std::string format;
	file >> format;
	if (format != "P3")
	{
		std::cerr << "Invalid PPM format: " << format << std::endl;
		return;
	}
	char c;
	file.get(c);
	file.get(c);
	if (c == '#')
	{
		std::getline(file, format);
	} else{
		std::cout << "No comment" << std::endl;
		file.putback(c);
	}
	
	// Max maxColor is 256
	file >> width >> height >> maxColor;
	if (maxColor > 256)
	{
		std::cerr << "Invalid maxColor: " << maxColor << std::endl;
		return;
	}

	pixels = new unsigned char*[height];
	for (int y = 0; y < height; ++y) {
		pixels[y] = new unsigned char[width*3];
		for (int x = 0; x < width*3; x += 3) {

			static std::string tempRed, tempGreen, tempBlue;
			file >> tempRed;
			file >> tempGreen;
			file >> tempBlue;

			pixels[y][x] = (unsigned char) (std::stoi(tempRed));
			pixels[y][x + 1] = (unsigned char) (std::stoi(tempGreen));
			pixels[y][x + 2] = (unsigned char) (std::stoi(tempBlue));

		}
	}

	// std::cout << "File read successfully" << std::endl;

	file.close();
}

ppm::~ppm()
{
	// Deallocate memory for the pixels
	for (int i = 0; i < height; ++i)
	{
		delete[] pixels[i];
	}
	delete[] pixels;
}

int ppm::getWidth()
{
	return width;
}

int ppm::getHeight()
{
	return height;
}

int ppm::getMaxColor()
{
	return maxColor;
}

unsigned char **ppm::getPixels()
{
	return pixels;
}

void ppm::draw()
{
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width * 3; j += 3)
			DrawPixel(j / 3, i, {pixels[i][j], pixels[i][j + 1], pixels[i][j + 2], 255});
}