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

void Bar::updatePosition(unsigned int FPS, Point& gameUpperLeft, Point& gameDownRight){
    this->shouldMove(FPS, gameUpperLeft, gameDownRight);
}

void Bar::draw()
{
    Rectangle rec = {this->coords.getX(), this->coords.getY(), this->getPixelWidth(), this->getPixelHeight()};
    DrawRectangleRounded(rec, 0.40, 0, this->color);

}

bool Bar::shouldMove(unsigned int FPS, Point& gameUpperLeft, Point& gameDownRight){


    if(IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_RIGHT)){
        this->dontMove();
        return false;
    }
    if(IsKeyDown(KEY_LEFT)){
        this->moveLeft(FPS, gameUpperLeft);
        return true;
    }
    if(IsKeyDown(KEY_RIGHT)){
        this->moveRight(FPS, gameDownRight);
        return true;
    }

    return false;

}

void Bar::moveRight(unsigned int FPS, Point& gameDownRight)
{
    this->coords.setX(this->coords.getX() + (static_cast<float>(4*60))/FPS);
}

void Bar::moveLeft(unsigned int FPS, Point& gameUpperLeft)
{
    this->coords.setX(this->coords.getX() - (static_cast<float>(4*60))/FPS);
}

void Bar::dontMove()
{
}

bool Bar::checkCollision(ScreenCoords coords)
{
    return false;
}
