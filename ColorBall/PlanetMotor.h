#pragma once
#include "RigidBody.h"
class PlanetMotor
{
public:
	PlanetMotor();
	~PlanetMotor();

	float rotSpeed;

	void update(RigidBody &b);
};

