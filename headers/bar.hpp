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

public:

    Bar(ScreenCoords coords, Color color, float pixelWidth, float pixelHeight);

    bool checkCollision(ScreenCoords coords);

    ScreenCoords getCoords() const;
    void setCoords(ScreenCoords& coords);

    float getPixelWidth() const;
    float getPixelHeight() const;

    void moveRight();
    void moveLeft();
    void dontMove();

    void draw();

};

#endif