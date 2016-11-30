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
	sprintSpeed = 3000;

	turnSpeed = .2f;	
}


Spaceship::~Spaceship()
{
}

void Spaceship::doVert(float val)
{
	vertThrust = val;
}

void Spaceship::doHoriz(float val)
{
	horizThrust += val;
}

void Spaceship::doTurn(float val)
{
	turnThrust = val;
}

void Spaceship::doStop(float val)
{
	stopAction += val;
}


void Spaceship::update(Transform &trans, RigidBody & rigid)
{

	//printf("%f, %f - %f\n", roundf(abs(rigid.velocity.x)), roundf(abs(rigid.velocity.y)), roundf(abs(rigid.velocity.x + rigid.velocity.y)));
	//If the ship isn't moving too fast, move in the direction the transform is facing
	if(abs(rigid.velocity.x + rigid.velocity.y) < maxSpeed && abs(rigid.velocity.x) < maxSpeed && abs(rigid.velocity.y) < maxSpeed)
	{ 
		rigid.addForce(trans.getUp() * speed * vertThrust);
		rigid.addForce(-perp(trans.getUp()) * speed * horizThrust);
	}
		

	//More direct turning, less space-y but more suited to the game
	trans.rotAngle += turnThrust * turnSpeed;

	//rigid.addTorque(turnThrust * turnSpeed);

	//Stop ship (in 1 sec)
	rigid.addForce(-rigid.velocity);// *breakPower * stopAction);
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
