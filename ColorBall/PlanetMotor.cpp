#include "PlanetMotor.h"
#include "sfwdraw.h"



PlanetMotor::PlanetMotor()
{
}


PlanetMotor::~PlanetMotor()
{
}

void PlanetMotor::update(RigidBody & b)
{
	b.addTorque(rotSpeed);

	//Make it not accelerate
	//b.angVel = 0;
}