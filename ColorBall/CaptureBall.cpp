#include "CaptureBall.h"
#include "sfwdraw.h"
#include "shapedraw.h"

#include <cstdlib>
#include <ctime>
using namespace sfw;


CaptureBall::CaptureBall()
{
	srand(time(0));

	vec2 hullVerts[] = { {1, 2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {2,1} };
	collider.hull = Hull(hullVerts, 8);

	transform.scl = vec2{ 5,5 };

	rigidbody.mass = .1f;
	rigidbody.drag = 1.f;

	//moveTimer = 0;
	turnTimer = 0;
}

CaptureBall::~CaptureBall()
{
}

void CaptureBall::update(float deltaTime, GameState & gs)
{
	//Move the ball in a random direction and reset the move timer to something between 2 and 4
	//moveTimer = 1;

	rigidbody.addForce(transform.getUp() * vec2{ 500, 500 } * deltaTime);

	if (turnTimer <= 0)
	{
		turnTimer = (rand() % 5) + 2;
		//rigidbody.drag = moveTimer / 10;

		//rigidbody.addForce(moveDir);
		//rigidbody.velocity = moveDir;
		rigidbody.addTorque(10 * (rand() % 200) - 100);
	}
	//moveTimer -= deltaTime;
	turnTimer -= deltaTime;
	
	//rigidbody.addForce(vec2{ 1,1 });
	rigidbody.integrate(transform, deltaTime);
}

void CaptureBall::draw(const mat3 & camera)
{
	mat3 glob = camera * transform.getGlobalTransform();

	//collider.DebugDraw(camera, transform);
	collider.StaticDraw(glob, team.color);
	//collider.Draw(camera, transform, team.color);
	//rigidbody.debugDraw(transform, camera);
}
