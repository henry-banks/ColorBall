#include "CaptureBall.h"
#include "sfwdraw.h"
#include "shapedraw.h"

#include <cstdlib>
#include <ctime>
using namespace sfw;


void CaptureBall::baseInit()
{
	srand(time(0));

	vec2 hullVerts[] = { { 2,4 },{ -2,4 },{ -4,2 },{ -4,-2 },{ -2,-4 },{ 2,-4 },{ 4,-2 },{ 4,2 } };
	collider = Collider(hullVerts, 8);

	transform.scl = vec2{ 2,2 };

	rigidbody.mass = .1f;
	rigidbody.drag = 1.f;

	turnTimer = 0;
}

CaptureBall::CaptureBall()
{
	baseInit();
}

CaptureBall::CaptureBall(int xBound, int yBound)
{
	baseInit();
	float x = rand() % (xBound * 2) - xBound;
	float y = rand() % (yBound * 2) - yBound;

	transform.pos = vec2{ x,y };
	transform.rotAngle = rand();
}

CaptureBall::~CaptureBall()
{
}

void CaptureBall::update(float deltaTime, GameState & gs)
{
	//Move the ball in a random direction and reset the move timer to something between 2 and 4
	rigidbody.addForce(transform.getUp() * vec2{ 500, 500 } * deltaTime);

	if (turnTimer <= 0)
	{
		turnTimer = (rand() % 5) + 2;
		rigidbody.addTorque(10 * (rand() % 200) - 100);
	}
	turnTimer -= deltaTime;
	
	rigidbody.integrate(transform, deltaTime);
}

void CaptureBall::draw(const mat3 & camera)
{
	mat3 glob = camera * transform.getGlobalTransform();

	//collider.DebugDraw(glob, transform);
	collider.Draw(camera, transform, team.color);
	//rigidbody.debugDraw(transform, camera);
}
