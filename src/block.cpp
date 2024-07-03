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
    std::cout << "Drawing block at " << upLeftPos.getX() << ", " << upLeftPos.getY() << std::endl;
    DrawRectangleRec(rec, RED);
}

        
bool Block::ballCollision(Ball * ball, Point& newPos){
    
    if(newPos.getX() - ball->getR() > upLeftPos.getX() + width ||
        newPos.getX() + ball->getR() < upLeftPos.getX())
    {
        return false;
    }

    if(ball->getDirection().getX() < 0){
        if(ball->getDirection().getY() < 0){
            // collides with either bottom or left
            if(newPos.getY() - ball->getR() > upLeftPos.getY() + height ||
                newPos.getY() + ball->getR() < upLeftPos.getY() + height){
                return false;
            } else if(newPos.getY() - ball->getR() < upLeftPos.getY() + height/3*2)
            {
                // collides with left
                ball->setDirection(Point(-ball->getDirection().getX(), ball->getDirection().getY()));
                return true;
            } else{
                // collides with bottom
                ball->setDirection(Point(ball->getDirection().getX(), -ball->getDirection().getY()));
                return true;
            }
        }
        else if (ball->getDirection().getY() > 0){
            // collides with either top or left
            if(newPos.getY() + ball->getR() < upLeftPos.getY() ||
                newPos.getY() - ball->getR() > upLeftPos.getY() - height){
                return false;
            }
            else if(newPos.getY() + ball->getR() > upLeftPos.getY() - height/3)
            {
                // collides with left
                ball->setDirection(Point(-ball->getDirection().getX(), ball->getDirection().getY()));
                return true;
            }
            else{
                // collides with top
                ball->setDirection(Point(ball->getDirection().getX(), -ball->getDirection().getY()));
                return true;
            }
            
        }
    }
    else if(ball->getDirection().getX() > 0){
        if(ball->getDirection().getY() < 0){ // ↖
            // collides with either bottom or right
            if(newPos.getY() - ball->getR() > upLeftPos.getY() + height ||
                newPos.getY() + ball->getR() < upLeftPos.getY() + height){
                return false;
            } else if(newPos.getY() - ball->getR() < upLeftPos.getY() + height/3*2)
            {
                // collides with right
                ball->setDirection(Point(-ball->getDirection().getX(), ball->getDirection().getY()));
                return true;
            } else{
                // collides with bottom
                ball->setDirection(Point(ball->getDirection().getX(), -ball->getDirection().getY()));
                return true;
            }
        }
        else if(ball->getDirection().getY() > 0){ // ↙
            // collides with either top or right
            if(newPos.getY() + ball->getR() < upLeftPos.getY() ||
                newPos.getY() - ball->getR() > upLeftPos.getY() - height){
                return false;
            }
            else if(newPos.getY() + ball->getR() > upLeftPos.getY() - height/3)
            {
                // collides with right
                ball->setDirection(Point(-ball->getDirection().getX(), ball->getDirection().getY()));
                return true;
            }
            else{
                // collides with top
                ball->setDirection(Point(ball->getDirection().getX(), -ball->getDirection().getY()));
                return true;
            }
        }
    }
    else{ // collides 
        if(ball->getDirection().getY() < 0){
            // collides with bottom
            if(newPos.getY() - ball->getR() > upLeftPos.getY() + height){
                return false;
            }
            else{
                ball->setDirection(Point(ball->getDirection().getX(), -ball->getDirection().getY()));
                return true;
            }
        }
        else{
            // collides with top
            if(newPos.getY() + ball->getR() < upLeftPos.getY()){
                return false;
            }
            else{
                ball->setDirection(Point(ball->getDirection().getX(), -ball->getDirection().getY()));
                return true;
            }
        }
    }

}