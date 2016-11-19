#pragma once
#include "Spaceship.h"

class SpriteController
{
public:
	SpriteController();
	~SpriteController();

	void update(Spaceship &ship, const Transform &currentPos);
};

