#pragma once
#include "Collider.h"
#include "PlayerShip.h"
class CaptureBall
{
	//For easy value adjustment
	void baseInit();
public:
	CaptureBall();
	CaptureBall(int xBound, int yBound);
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

