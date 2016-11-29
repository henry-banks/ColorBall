#pragma once
#include "Collider.h"
#include "Spaceship.h"

struct Team
{
	unsigned color = 0xffffffff;
	int teamNum = 0;
};

class PlayerSprite
{
public:
	PlayerSprite();
	~PlayerSprite();

	float vertThrust;
	float horizThrust;

	float speed;
	float maxSpeed;
	float turnSpeed;

	Transform transform;
	Collider collider;
	RigidBody rigidbody;
	Spaceship ship;
	Team team;

	unsigned color;

	void doThrust(float val);
	void doTurn(float val);

	void update(float deltaTime, const vec2 &movement, class GameState &gs);
	void draw(const mat3 &camera);

};

