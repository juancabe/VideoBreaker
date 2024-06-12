#include "../headers/bar.hpp"


Bar::Bar(ScreenCoords coords, Color color, float pixelWidth, float pixelHeight)
    : coords(coords.getX(), coords.getY())
{
    this->color = color;
    this->pixelWidth = pixelWidth;
    this->pixelHeight = pixelHeight;

}

ScreenCoords Bar::getCoords() const
{
    return this->coords;
}

void Bar::setCoords(ScreenCoords& coords)
{
    this->coords = coords;
}

float Bar::getPixelWidth() const
{
    return this->pixelWidth;
}

float Bar::getPixelHeight() const
{
    return this->pixelHeight;
}

void Bar::draw()
{
    Rectangle rec = {this->coords.getX(), this->coords.getY(), this->getPixelWidth(), this->getPixelHeight()};
    DrawRectangleRounded(rec, 0.5, 0, this->color);

}


void Bar::moveRight()
{
    this->coords.setX(this->coords.getX() + 1);
}

void Bar::moveLeft()
{
    this->coords.setX(this->coords.getX() - 1);
}

void Bar::dontMove()
{
}

bool Bar::checkCollision(ScreenCoords coords)
{
    return false;
}
