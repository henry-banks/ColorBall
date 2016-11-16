#pragma once
#include "Transform.h"
#include "Collider.h"

class Asteroid
{
public:
	Asteroid();
	~Asteroid();

	Transform	transform;
	Collider	collider;
	RigidBody	rigidbody;

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};

