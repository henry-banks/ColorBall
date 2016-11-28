#include "CaptureBall.h"
#include "sfwdraw.h"
#include "shapedraw.h"

#include <cstdlib>
#include <ctime>
using namespace sfw;


CaptureBall::CaptureBall()
{
	vec2 hullVerts[] = { { 2,4 },{ -2,4 },{ -4,2 },{ -4,-2 },{ -2,-4 },{ 2,-4 },{ 4,-2 },{ 4,2 } };
	collider = Collider(hullVerts, 8);

	rigidbody.mass = .1f;
	rigidbody.drag = .1f;

	moveTimer = 0;
	turnTimer = 0;
}


CaptureBall::~CaptureBall()
{
}

void CaptureBall::update(float deltaTime, GameState & gs)
{
	if (moveTimer <= 0)
	{
		//Move the ball in a random direction and reset the move timer to something between 2 and 4
		//moveDir = (rand() % 200) -100.f * vec2{ 1, 1 };
		moveTimer = 1;

		//rigidbody.velocity = vec2{ 0,0 };
		rigidbody.addForce(transform.getUp() * vec2 { 50, 50 });
	}
	if (turnTimer <= 0)
	{
		turnTimer = (rand() % 5) + 2;
		//rigidbody.drag = moveTimer / 10;

		//rigidbody.addForce(moveDir);
		//rigidbody.velocity = moveDir;
		rigidbody.addTorque(10 * (rand() % 200) - 100);
	}
	moveTimer -= deltaTime;
	turnTimer -= deltaTime;

	//rigidbody.addForce(vec2{ 1,1 });
	rigidbody.integrate(transform, deltaTime);
}

void CaptureBall::draw(const mat3 & camera)
{
	mat3 glob = camera * transform.getGlobalTransform();

	spd::drawCircle(glob * Circle{ 0,0,2 }, team.color);
	//collider.Draw(camera, transform, team.color);
	//rigidbody.debugDraw(transform, camera);
}
