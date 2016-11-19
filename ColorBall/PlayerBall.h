#pragma once
#include "Collider.h"
#include "PlayerSprite.h"
class PlayerBall
{
public:
	PlayerBall();
	~PlayerBall();

	Collider collider;
	Transform transform;
	RigidBody rigidbody;
	Team team;

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
};

