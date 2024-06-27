#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

#include "bar.hpp"

class GameModel{

private:
	Bar * bar;
	unsigned int FPS;

public:
	GameModel();
	void update();
	unsigned int getFPS();

};

#endif