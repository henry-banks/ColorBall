#include "PlayerShip.h"
#include "GameState.h"


PlayerShip::PlayerShip()
{
	vec2 hullVerts[] = { {0,3},{-2,-3},{2,-3} };
	collider = Collider(hullVerts, 3);

	transform.scl = vec2{ 4,4 };

	rigidbody.mass = 5;
	rigidbody.angDrag = 5;
}


PlayerShip::~PlayerShip()
{
}

void PlayerShip::update(float deltaTime, float turnAngle)
{
	controller.update(spaceship, turnAngle);
	spaceship.update(transform, rigidbody);
	rigidbody.integrate(transform, deltaTime);
}

void PlayerShip::draw(const mat3 &camera)
{
	//transform.debugDraw(camera);
	//rigidbody.debugDraw(transform, camera);

	collider.Draw(camera, transform, team.color);
}
