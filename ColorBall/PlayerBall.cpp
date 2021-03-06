#include "PlayerBall.h"



PlayerBall::PlayerBall()
{
	vec2 hullVerts[] = { {2,4}, {-2,4}, {-4,2},{-4,-2},{-2,-4},{2,-4},{4,-2},{4,2} };

	//Make the size of the collider equal to the size of the transform
	/*for (int i = 0; i < 8; i++)
		hullVerts[i] *= 6;*/

	collider = Collider(hullVerts, 8);

	transform.scl = vec2{ 6,6 };

	rigidbody.drag = 3.f;
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
	//collider.DebugDraw(camera, transform);
	collider.Draw(camera, transform, team.color);
	//rigidbody.debugDraw(transform, camera);
}
