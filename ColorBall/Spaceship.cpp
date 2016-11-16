#include "Spaceship.h"
#include "sfwdraw.h"
#include <iostream>

using namespace sfw;


Spaceship::Spaceship()
{
	vertThrust = 0;
	horizThrust = 0;
	breakPower = 4.0f;
	stopAction = 0.0f;
	

	speed = 500;
	maxSpeed = 1000;

	turnSpeed = 20.f;
	
}


Spaceship::~Spaceship()
{
}

void Spaceship::doThrust(float val)
{
	vertThrust += val;
}

void Spaceship::doTurn(float val)
{
	horizThrust += val * 10;
}

void Spaceship::doStop(float val)
{
	stopAction += val;
}


void Spaceship::update(const Transform &trans, RigidBody & rigid)
{
	//Move in the direction the transform is facing
	rigid.addForce(trans.getUp() * speed * vertThrust);
	rigid.addTorque(turnSpeed * horizThrust);

	//Stop ship (in 1 sec)
	rigid.addForce(-rigid.velocity * breakPower * stopAction);
	//rigid.addTorque(-rigid.angVel * breakPower * stopAction);
	//std::cout << -rigid.angVel * breakPower * stopAction << "\n";

	//If the ship is going faster than the max speed...
	//if (magnitude(rigid.velocity) > maxSpeed)
	//{
	//	//Get the direction
	//	vec2 dir = normalize(rigid.velocity);

	//	//Set the velocity to be the direction, going at MAXIMUM SPEED.
	//	rigid.velocity = dir * maxSpeed;
	//}

	horizThrust = vertThrust = stopAction = 0;
}
