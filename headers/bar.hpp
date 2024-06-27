#ifndef BAR_HPP
#define BAR_HPP

#include <raylib.h>
#include "../headers/coords.hpp"

class Bar{

private:
    ScreenCoords coords;
    Color color;
    float pixelWidth;
    float pixelHeight;

    bool shouldMove(unsigned int FPS);
    void moveRight(unsigned int FPS);
    void moveLeft(unsigned int FPS);
    void dontMove();

public:

    Bar(ScreenCoords coords, Color color, float pixelWidth, float pixelHeight);

    bool checkCollision(ScreenCoords coords);

    ScreenCoords getCoords() const;
    void setCoords(ScreenCoords& coords);

    float getPixelWidth() const;
    float getPixelHeight() const;


    void updatePosition(unsigned int FPS);
    void draw();

};

#endif