#include "PlayerBall.h"



PlayerBall::PlayerBall()
{
	vec2 hullVerts[] = { {2,4}, {-2,4}, {-4,2},{-4,-2},{-2,-4},{2,-4},{4,-2},{4,2} };
	collider = Collider(hullVerts, 8);

	transform.scl = vec2{ 6,6 };

	rigidbody.drag = 1.0f;
	rigidbody.angDrag = 0.5f;
	rigidbody.mass = 10;
}


PlayerBall::~PlayerBall()
{
}

void PlayerBall::update(float deltaTime, GameState & gs)
{
	rigidbody.integrate(transform, deltaTime);
}

void PlayerBall::draw(const mat3 & camera)
{
	//transform.debugDraw(camera);
	collider.Draw(camera, transform, team.color);
	rigidbody.debugDraw(transform, camera);
}
