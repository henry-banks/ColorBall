#include "ParticleSpawner.h"

void ParticleSpawner::update(float deltaTime, GameState & gs)
{
	if (spawnTimer <= 0 && !(particlePool.isValid(maxParticles+1)))
	{
		Particle p;
		p.transform = transform;
		particlePool.push(p);
	}

	for (auto iter = particlePool.begin(); iter != particlePool.end(); iter++)
	{
		if (iter.isValid())
		{
			iter.value().update(deltaTime, gs);
		}
	}
}

void ParticleSpawner::draw(const mat3 & camera)
{
	for (auto iter = particlePool.begin(); iter != particlePool.end(); iter++)
	{
		if (iter.isValid())
		{
			iter.value().draw(camera);
		}
	}
}
