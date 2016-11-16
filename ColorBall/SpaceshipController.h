#pragma once
#include "Spaceship.h"

class SpaceshipController
{
public:
	//SpaceshipController();
	SpaceshipController(unsigned aCTR_LEFT = 'A', unsigned aCTR_RIGHT = 'D'
		, unsigned aCTR_UP = 'W', unsigned aCTR_DOWN = 'S', unsigned aCTR_BREAK = ' ');
	~SpaceshipController();

	unsigned CTR_LEFT, CTR_RIGHT, CTR_UP, CTR_DOWN, CTR_BREAK;

	void update(Spaceship &ship);
};

