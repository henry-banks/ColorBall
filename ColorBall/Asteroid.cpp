#include "Asteroid.h"
#include "GameState.h"


Asteroid::Asteroid()
{
	vec2 hullVerts[] = { {-10,-6},{0,6},{10,-6} };
	collider = Collider(hullVerts, 3);

	transform.scl = vec2{ 12,12 };
	
	rigidbody.drag = 0.0f;
	rigidbody.angDrag = 0.0f;
	rigidbody.mass = 10;
}


Asteroid::~Asteroid()
{
}

void Asteroid::update(float deltaTime, GameState & gs)
{
	rigidbody.integrate(transform, deltaTime);
}

void Asteroid::draw(const mat3 & camera)
{
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(transform, camera);
}
