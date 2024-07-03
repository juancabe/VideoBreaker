#include "../headers/bar.hpp"
#include "../headers/ball.hpp"

#include <math.h>

Bar::Bar(ScreenCoords coords, Color color, float pixelWidth, float pixelHeight, unsigned int FPS)
    : coords(coords.getX(), coords.getY()), v((static_cast<float>(4*60))/FPS)
{
    this->color = color;
    this->pixelWidth = pixelWidth;
    this->pixelHeight = pixelHeight;
    this->roundedRadious = static_cast<int>(pixelHeight)/2;
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
    Rectangle rec = {coords.getX() + static_cast<float>(roundedRadious), coords.getY(),
                    getPixelWidth() - static_cast<float>(roundedRadious)*2, getPixelHeight()};
    DrawRectangleRec(rec, RED);
    DrawCircle(static_cast<int>(coords.getX()) + roundedRadious, // left circle
                static_cast<int>(coords.getY())+rec.height/2, roundedRadious, RED);
    DrawCircle(static_cast<int>(coords.getX()) + pixelWidth - roundedRadious, 
                static_cast<int>(coords.getY())+rec.height/2, roundedRadious, RED);

    DrawCircle(coords.getX(), coords.getY() + pixelHeight/2, 2, WHITE);
    DrawCircle(coords.getX() + pixelWidth, coords.getY() + pixelHeight/2, 2, WHITE);

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

bool Bar::ballCollision(Ball * ball, Point& newPos)
{   
    int r = ball->getR();

    if((newPos.getY() + r) < this->coords.getY() || // The ball->is upper than the bar
        newPos.getX() < this->coords.getX() || // The ball->is at the left of the bar
        newPos.getX() > (this->coords.getX() + this->pixelWidth)) // The ball->is at the right of the bar
    {
        return false;
    }

    // Being down the bar...

    if(newPos.getX() > (coords.getX() + roundedRadious) &&
        newPos.getX() < (coords.getX() + pixelWidth - roundedRadious)) // Ball is at the plain surface of the bar
    {
        ball->setDirection(Point(ball->getDirection().getX(), -ball->getDirection().getY()));
        return true;
    }
    // Ball is at the rounded surface of the bar
    if(newPos.getX() > coords.getX() && newPos.getX() <= (coords.getX() + roundedRadious)) // left one
    {   
        float d = coords.getX() + static_cast<float>(roundedRadious) - (newPos.getX() + ball->getR()*(newPos.getX()/coords.getX())); // distance between surface +- of ball x and circle x
        float h = sin(acos(d/roundedRadious))*roundedRadious; // y distance between ball surface and center of (circle of bar)
        float dh = roundedRadious - h;
        if((newPos.getY() + ball->getR()) < (coords.getY() + dh)){
            return false;
        } else{
            int x;
            Point surfaceVector = Point(coords.getX() + roundedRadious, coords.getY()+getPixelHeight()/2);
            Point nVector = newPos - surfaceVector;
            nVector.normalizeToOne();
            Point calc = nVector - ball->getDirection();
            calc.normalizeToOne();
            ball->setDirection(calc);
            return true;
        }
    }
    if(newPos.getX() < (coords.getX() + pixelWidth)){ // right one
        float d = (newPos.getX() - ball->getR()*(newPos.getX()/coords.getX())) - (coords.getX() + pixelWidth - roundedRadious); // distance between surface +- of ball x and circle x
        float h = sin(acos(d/roundedRadious))*roundedRadious; // y distance between ball surface and center of (circle of bar)
        float dh = roundedRadious - h;
        if((newPos.getY() + ball->getR()) < (coords.getY() + dh)){
            return false;
        } else{
            int x;
            Point surfaceVector = Point(coords.getX() + pixelWidth - roundedRadious, coords.getY()+getPixelHeight()/2);
            Point nVector =  newPos - surfaceVector;
            nVector.normalizeToOne();
            Point calc = nVector - ball->getDirection();
            calc.normalizeToOne();
            ball->setDirection(calc);
            return true;
        }
    }

    return false;
}