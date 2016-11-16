#pragma once
#include "Transform.h"
#include "Collider.h"
#include "RigidBody.h"
#include "SpaceshipController.h"
#include "Spaceship.h"

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
	float health;


	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};

