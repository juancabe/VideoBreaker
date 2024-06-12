#include "../headers/coords.hpp"

// WorldCoords

WorldCoords::WorldCoords(float x, float y){
    this->setX(x);
    this->setY(y);
}

float WorldCoords::getX() const {return this->x;};
float WorldCoords::getY() const {return this->y;};

void WorldCoords::setX(float x){
    this->x = x;
};
void WorldCoords::setY(float y){
    this->y = y;
};

ScreenCoords * WorldCoords::toScreen(){
    return new ScreenCoords(this->getX()*worldDims.pixelPerLogicSpace + posInScreen.x,
                            this->getY()*worldDims.pixelPerLogicSpace + posInScreen.y);
}

// ScreenCoords

ScreenCoords::ScreenCoords(float x, float y){
    this->setX(x);
    this->setY(y);
}

float ScreenCoords::getX() const {return this->x;};
float ScreenCoords::getY() const {return this->y;};

void ScreenCoords::setX(float x){
    this->x = x;
};
void ScreenCoords::setY(float y){
    this->y = y;
};

WorldCoords * ScreenCoords::toWorld(){
    return new WorldCoords((this->getX() - posInScreen.x)/worldDims.pixelPerLogicSpace,
                            (this->getY() - posInScreen.y)/worldDims.pixelPerLogicSpace);
}