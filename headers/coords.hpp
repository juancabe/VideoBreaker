#ifndef WORLDCOORDS_HPP
#define WORLDCOORDS_HPP

class ScreenCoords;

struct {
    int screenHeight = 600;
    int screenWidth = 1000;
} screenDims;

struct{
    unsigned int logicHeight = 60;
    unsigned int logicWidth = 100;
    unsigned int pixelPerLogicSpace = 5;
} worldDims;

struct {
    int x = screenDims.screenWidth/2 -
            worldDims.logicWidth/2*
            worldDims.pixelPerLogicSpace;
    int y;
}posInScreen;

class WorldCoords {

private:
    float x;
    float y;

public:
    // Constructor
    WorldCoords(float x, float y);

    // Getter methods
    float getX() const;
    float getY() const;

    // Setter methods
    void setX(float x);
    void setY(float y);
    
    ScreenCoords * toScreen();

};


class ScreenCoords {

private:
    float x;
    float y;

public:
    // Constructor
    ScreenCoords(float x, float y);

    // Getter methods
    float getX() const;
    float getY() const;

    // Setter methods
    void setX(float x);
    void setY(float y);
    
    WorldCoords * toWorld();

};

#endif // WORLDCOORDS_HPP