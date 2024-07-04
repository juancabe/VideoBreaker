#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "point.hpp"
#include "ball.hpp"

class Block{
    private:
        Point upLeftPos;
        bool spawnsBall;
        Color color;
    public:

        static const int width = 8;
        static const int height = 8;
        static const int margin = 1;

        Block(Point upLeftPos, bool spawnsBall = false);

        Point getUpLeftPos() const;
        bool getSpawnsBall() const;

        void setPos(Point& pos);

        void draw();
        bool ballCollision(Ball * ball, Point& newPos);
};


#endif