#include "PlayerShip.h"
#include "GameState.h"


PlayerShip::PlayerShip()
{
	vec2 hullVerts[] = { {0,3},{-2,-3},{2,-3} };
	collider = Collider(hullVerts, 3);

	transform.scl = vec2{ 4,4 };

	rigidbody.mass = 5;
	rigidbody.drag = 1;
	rigidbody.angDrag = 5;
}


PlayerShip::~PlayerShip()
{
}

void PlayerShip::update(float deltaTime, float turnAngle, float currentAngle)
{
	controller.update(spaceship, turnAngle, currentAngle);
	spaceship.update(transform, rigidbody);
	rigidbody.integrate(transform, deltaTime);
}

void PlayerShip::draw(const mat3 &camera)
{
	//rigidbody.debugDraw(transform, camera);

	collider.Draw(camera, transform, team.color);
}
