#pragma once
#include "RigidBody.h"

class Spaceship
{

	float vertThrust;
	float horizThrust;
	float turnThrust;

	float turnSpeed;
	float breakPower;
	float stopAction;

	float speed;
public:
	Spaceship();
	~Spaceship();

	float maxSpeed;
	float sprintSpeed;

	void doVert(float val);
	void doHoriz(float val);
	void doTurn(float val);
	void doStop(float val);

	void update(Transform &trans, RigidBody &rigid);

};

