#include "PlayerShip.h"
#include "GameState.h"


PlayerShip::PlayerShip()
{
	vec2 hullVerts[] = { {0,3},{-2,-3},{2,-3} };
	collider = Collider(hullVerts, 3);

	transform.scl = vec2{ 10,10 };
}


PlayerShip::~PlayerShip()
{
}

void PlayerShip::update(float deltaTime, GameState & gs)
{
	controller.update(spaceship);
	spaceship.update(transform, rigidbody);
	rigidbody.integrate(transform, deltaTime);
}

void PlayerShip::draw(const mat3 &camera)
{
	transform.debugDraw(camera);
	rigidbody.debugDraw(transform, camera);

	collider.DebugDraw(camera, transform);
}
