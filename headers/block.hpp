#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "point.hpp"
#include "ball.hpp"

class Block{
    private:
        Point upLeftPos;
    public:
        static const int width = 10;
        static const int height = 10;
        static const int margin = 5;
        Block(Point upLeftPos);
        Point getUpLeftPos() const;
        void setPos(Point& pos);
        void draw();
        bool ballCollision(Ball * ball, Point& ballPos);
};


#endif