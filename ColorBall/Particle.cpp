#include "Particle.h"

bool Particle::isExpired() const
{
	return lifetime <= 0;
}

void Particle::update(float deltaTime, GameState & gs)
{
	lifetime -= deltaTime;
}

void Particle::draw(const mat3 & camera)
{
	transform.debugDraw(camera);
}

void Particle::reset(float initial)
{
	lifetime = initial;
}
