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

        static const int width = 7;
        static const int height = 7;
        static const int margin = 1;

        ~Block(){
            
        }
        Block(Point upLeftPos, bool spawnsBall = false);

        Point getUpLeftPos() const;
        bool getSpawnsBall() const;

        void setPos(Point& pos);

        void draw();
        bool ballCollision(Ball * ball, Point& newPos);
};


#endif