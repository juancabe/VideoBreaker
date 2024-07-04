#include "../headers/block.hpp"
#include <iostream>
#include <raylib.h>
#include <random>

Block::Block(Point upLeftPos, bool spawnsBall)
    : upLeftPos(upLeftPos), spawnsBall(spawnsBall)
{
    this->color.a = 255;
    this->color.r = rand()%199 + 28;
    this->color.g = rand()%199 + 28;
    this->color.b = rand()%199 + 28;
}

Point Block::getUpLeftPos() const
{
    return upLeftPos;
}

void Block::setPos(Point& pos)
{
    upLeftPos = pos;
}

void Block::draw()
{
    Rectangle rec = {
        upLeftPos.getX(),
        upLeftPos.getY(),
        width,
        height
    };
    DrawRectangleRec(rec, this->color);

    unsigned char c255 = static_cast<unsigned char>('\255');

    if(spawnsBall){
        DrawCircle(upLeftPos.getX() + static_cast<float>(width)/2, upLeftPos.getY() + static_cast<float>(height)/2,
                    static_cast<float>(width)/4,{
                        static_cast<unsigned char>(c255 - this->color.r),
                        static_cast<unsigned char>(c255 - this->color.g),
                        static_cast<unsigned char>(c255 - this->color.b),
                        this->color.a,
                    });
    }
}

        
bool Block::ballCollision(Ball * ball, Point& newPos){

    // Top side of block
    if( (newPos.getY() + (static_cast<float>(ball->getR()))) > this->getUpLeftPos().getY() &&
        (newPos.getY() - (static_cast<float>(ball->getR()))) < this->getUpLeftPos().getY() &&
        (newPos.getX() + (static_cast<float>(ball->getR()))/300) < (this->getUpLeftPos().getX() + this->width) &&
        (newPos.getX() - (static_cast<float>(ball->getR()))/300) > this->getUpLeftPos().getX())
    {
        if(ball->getDirection().getY() > 0){
            ball->setDirection(Point(ball->getDirection().getX(), -ball->getDirection().getY()));
            return true;
        } else{
            return false;
        }

    }

    // Bottom side of block
    if( (newPos.getY() - ball->getR()) < (this->getUpLeftPos().getY() + this->height) &&
        (newPos.getY() + ball->getR()) > (this->getUpLeftPos().getY() + this->height) &&
        (newPos.getX() + (static_cast<float>(ball->getR()))/300) < (this->getUpLeftPos().getX() + this->width) &&
        (newPos.getX() - (static_cast<float>(ball->getR()))/300) > this->getUpLeftPos().getX())
    {
        if(ball->getDirection().getY() < 0){
            ball->setDirection(Point(ball->getDirection().getX(), -ball->getDirection().getY()));
            return true;
        } else{
            return false;
        }
    }

    // Left side of block
    if( (newPos.getX() + (static_cast<float>(ball->getR()))) > this->getUpLeftPos().getX() &&
        (newPos.getX() - (static_cast<float>(ball->getR()))) < this->getUpLeftPos().getX() &&
        (newPos.getY() + (static_cast<float>(ball->getR()))/300) < (this->getUpLeftPos().getY() + this->height) &&
        (newPos.getY() - (static_cast<float>(ball->getR()))/300) > this->getUpLeftPos().getY())
    {
        if(ball->getDirection().getX() > 0){
            ball->setDirection(Point(-ball->getDirection().getX(), ball->getDirection().getY()));
            return true;
        } else{
            return false;
        }
    }

    // Right side of block
    if( (newPos.getX() - (static_cast<float>(ball->getR()))) < (this->getUpLeftPos().getX() + this->width) &&
        (newPos.getX() + (static_cast<float>(ball->getR()))) > (this->getUpLeftPos().getX() + this->width) &&
        (newPos.getY() + (static_cast<float>(ball->getR()))/300) < (this->getUpLeftPos().getY() + this->height) &&
        (newPos.getY() - (static_cast<float>(ball->getR()))/300) > this->getUpLeftPos().getY())
    {
        if(ball->getDirection().getX() < 0){
            ball->setDirection(Point(-ball->getDirection().getX(), ball->getDirection().getY()));
            return true;
        } else{
            return false;
        }
    }

    return false;

}

bool Block::getSpawnsBall() const
{
    return spawnsBall;
}