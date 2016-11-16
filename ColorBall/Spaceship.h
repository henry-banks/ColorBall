#pragma once
#include "RigidBody.h"

class Spaceship
{

	float vertThrust;
	float horizThrust;

	float turnSpeed;
	float breakPower;
	float stopAction;

	float speed;
	float maxSpeed;
public:
	Spaceship();
	~Spaceship();

	void doThrust(float val);
	void doTurn(float val);
	void doStop(float val);

	void update(const Transform &trans, RigidBody &rigid);

};

