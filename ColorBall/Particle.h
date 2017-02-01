#pragma once

#include "Transform.h"
#include "RigidBody.h"

class Particle
{
public:
	Transform transform;
	RigidBody rigidbody;

	// remaining life
	float lifetime = 5;

	// Returns true if the particle is past its lifetime (lifetime < 0)
	bool isExpired() const;

	// Ticks down the lifetime and updates the rigidbody.
	void update(float deltaTime, class GameState &gs);

	// Draws the particle.
	void draw(const mat3 &camera);

	// Resets this particle's lifetime.
	void reset(float initial);
};