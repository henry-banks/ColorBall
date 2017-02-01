#pragma once

#include "ObjPool.h"
#include "Particle.h"

#include <vector>

class ParticleSpawner
{
	// Object pool is used to store particles.
	obpool<Particle> particlePool;

public:
	Transform transform;

	float spawnInterval, spawnTimer;            // time between each particle instantiation
	unsigned int maxParticles;      // maximum number of particles allowed

									// Updates every live particle.
									// Should call free on each particle that has expired.
									// Should attempt to add more particles after the specified interval.
	void update(float deltaTime, class GameState &gs);

	// Draws every live particle.
	void draw(const mat3 &camera);
};