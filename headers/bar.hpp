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

    const float v;

    bool shouldMove(Point& gameUpperLeft, Point& gameDownRight);
    void moveLeft(Point& gameUpperLeft);
    void moveRight(Point& gameDownRight);
    void dontMove();



public:

    Bar(ScreenCoords coords, Color color, float pixelWidth, float pixelHeight, unsigned int FPS);

    bool checkCollision(ScreenCoords coords);

    ScreenCoords getCoords() const;
    void setCoords(ScreenCoords& coords);

    float getPixelWidth() const;
    float getPixelHeight() const;


    void updatePosition(Point& gameUpperLeft, Point& gameDownRight);
    void draw();

};

#endif