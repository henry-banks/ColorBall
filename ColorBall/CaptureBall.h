#pragma once
#include "Collider.h"
#include "PlayerSprite.h"
class CaptureBall
{
public:
	CaptureBall();
	~CaptureBall();

	Collider collider;
	Transform transform;
	RigidBody rigidbody;
	Team team;

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};

