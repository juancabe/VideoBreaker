#include "../headers/block.hpp"
#include <iostream>
#include <raylib.h>

Block::Block(Point upLeftPos)
    : upLeftPos(upLeftPos)
{
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
    DrawRectangleRec(rec, RED);
}

        
bool Block::ballCollision(Ball * ball, Point& newPos){
    // Left side of block
    if( (newPos.getX() + (static_cast<float>(ball->getR()))) > this->getUpLeftPos().getX() &&
        (newPos.getX() - (static_cast<float>(ball->getR()))) < this->getUpLeftPos().getX() &&
        (newPos.getY() + (static_cast<float>(ball->getR()))/300) < (this->getUpLeftPos().getY() + this->height) &&
        (newPos.getY() - (static_cast<float>(ball->getR()))/300) > this->getUpLeftPos().getY())
    {
        ball->setDirection(Point(-ball->getDirection().getX(), ball->getDirection().getY()));
        std::cout << "Left" << std::endl;
        return true;
    }

    // Right side of block
    if( (newPos.getX() - (static_cast<float>(ball->getR()))) < (this->getUpLeftPos().getX() + this->width) &&
        (newPos.getX() + (static_cast<float>(ball->getR()))) > (this->getUpLeftPos().getX() + this->width) &&
        (newPos.getY() + (static_cast<float>(ball->getR()))/300) < (this->getUpLeftPos().getY() + this->height) &&
        (newPos.getY() - (static_cast<float>(ball->getR()))/300) > this->getUpLeftPos().getY())
    {
        ball->setDirection(Point(-ball->getDirection().getX(), ball->getDirection().getY()));
        std::cout << "Right" << std::endl;
        return true;
    }

    // Top side of block
    if( (newPos.getY() + (static_cast<float>(ball->getR()))) > this->getUpLeftPos().getY() &&
        (newPos.getY() - (static_cast<float>(ball->getR()))) < this->getUpLeftPos().getY() &&
        (newPos.getX() + (static_cast<float>(ball->getR()))/300) < (this->getUpLeftPos().getX() + this->width) &&
        (newPos.getX() - (static_cast<float>(ball->getR()))/300) > this->getUpLeftPos().getX())
    {
        ball->setDirection(Point(ball->getDirection().getX(), -ball->getDirection().getY()));
        std::cout << "Top" << std::endl;
        return true;
    }

    // Bottom side of block
    if( (newPos.getY() - ball->getR()) < (this->getUpLeftPos().getY() + this->height) &&
        (newPos.getY() + ball->getR()) > (this->getUpLeftPos().getY() + this->height) &&
        (newPos.getX() + (static_cast<float>(ball->getR()))/300) < (this->getUpLeftPos().getX() + this->width) &&
        (newPos.getX() - (static_cast<float>(ball->getR()))/300) > this->getUpLeftPos().getX())
    {
        ball->setDirection(Point(ball->getDirection().getX(), -ball->getDirection().getY()));
        std::cout << "Bottom" << std::endl;
        return true;
    }

    return false;

}