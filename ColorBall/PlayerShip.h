#pragma once
#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"
#include "SpaceshipController.h"
#include "Spaceship.h"

struct Team
{
	unsigned color = 0xffffffff;
	int teamNum = 0;
};

class PlayerShip
{
public:
	PlayerShip();
	~PlayerShip();

	Transform			transform;
	Collider			collider;
	RigidBody			rigidbody;
	SpaceshipController	controller;
	Spaceship			spaceship;

	Team team;
	float health;

	void update(float deltaTime, float turnAngle);
	void draw(const mat3 &camera);
};

