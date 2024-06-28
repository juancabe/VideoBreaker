#include "../headers/bar.hpp"

Bar::Bar(ScreenCoords coords, Color color, float pixelWidth, float pixelHeight, unsigned int FPS)
    : coords(coords.getX(), coords.getY()), v((static_cast<float>(4*60))/FPS)
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

void Bar::updatePosition(Point& gameUpperLeft, Point& gameDownRight){
    this->shouldMove(gameUpperLeft, gameDownRight);
}

void Bar::draw()
{
    Rectangle rec = {this->coords.getX(), this->coords.getY(), this->getPixelWidth(), this->getPixelHeight()};
    DrawRectangleRounded(rec, 0.40, 0, this->color);

}

bool Bar::shouldMove(Point& gameUpperLeft, Point& gameDownRight){


    if(IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_RIGHT)){
        this->dontMove();
        return false;
    }
    if(IsKeyDown(KEY_LEFT)){
        this->moveLeft(gameUpperLeft);
        return true;
    }
    if(IsKeyDown(KEY_RIGHT)){
        this->moveRight(gameDownRight);
        return true;
    }

    return false;

}

void Bar::moveRight(Point& gameDownRight)
{
    float newX = this->coords.getX() + this->v;
    if((newX + this->getPixelWidth()) < gameDownRight.getX()){
         this->coords.setX(newX);
         return;
    }
    if((this->coords.getX() + this->getPixelWidth()) >= gameDownRight.getX()){
        return;
    } else{
        this->coords.setX(gameDownRight.getX() - this->getPixelWidth());
    }
}
void Bar::moveLeft(Point& gameUpperLeft)
{
    float newX = this->coords.getX() - this->v;
    if(newX > gameUpperLeft.getX()){
         this->coords.setX(newX);
         return;
    }
    if(this->coords.getX() <= gameUpperLeft.getX()){
        return;
    } else{
        this->coords.setX(gameUpperLeft.getX());
    }

}

void Bar::dontMove()
{
}

bool Bar::checkCollision(ScreenCoords coords)
{
    return false;
}
