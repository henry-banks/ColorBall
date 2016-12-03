#pragma once
#include "Collider.h"
#include "PlayerShip.h"
class CaptureBall
{
public:
	CaptureBall();
	~CaptureBall();

	Collider collider;
	Transform transform;
	RigidBody rigidbody;
	Team team;

	//float moveTimer;
	float turnTimer;

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};

