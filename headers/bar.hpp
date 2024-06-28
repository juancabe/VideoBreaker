#ifndef BAR_HPP
#define BAR_HPP

#include <raylib.h>
#include "../headers/coords.hpp"
#include "../headers/point.hpp"

class Bar{

private:
    ScreenCoords coords;
    Color color;
    float pixelWidth;
    float pixelHeight;

    bool shouldMove(unsigned int FPS, Point& gameUpperLeft, Point& gameDownRight);
    void moveLeft(unsigned int FPS, Point& gameUpperLeft);
    void moveRight(unsigned int FPS, Point& gameDownRight);
    void dontMove();

public:

    Bar(ScreenCoords coords, Color color, float pixelWidth, float pixelHeight);

    bool checkCollision(ScreenCoords coords);

    ScreenCoords getCoords() const;
    void setCoords(ScreenCoords& coords);

    float getPixelWidth() const;
    float getPixelHeight() const;


    void updatePosition(unsigned int FPS, Point& gameUpperLeft, Point& gameDownRight);
    void draw();

};

#endif