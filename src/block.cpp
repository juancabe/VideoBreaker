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

        
bool Block::ballCollision(Ball * ball, Point& ballPos){
    
    if(ball->getDirection().getX() < 0){
        if(ball->getDirection().getY() < 0){
            // collides with either bottom or left
        }
        else{
            // collides with either top or left
        }
    }
    else if(ball->getDirection().getX() > 0){
        if(ball->getDirection().getY() < 0){
            // collides with either bottom or right
        }
        else{
            // collides with either top or right
        }
    }
    else{
        if(ball->getDirection().getY() < 0){
            // collides with bottom
        }
        else{
            // collides with top
        }
    }

}