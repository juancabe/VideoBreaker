#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "point.hpp"
#include "ball.hpp"

class Block{
    private:
        Point upLeftPos;
    public:
        static const int width = 15;
        static const int height = 15;
        static const int margin = 3;
        Block(Point upLeftPos);
        Point getUpLeftPos() const;
        void setPos(Point& pos);
        void draw();
        bool ballCollision(Ball * ball, Point& newPos);
};


#endif