#include "PlayerSprite.h"
#include "sfwdraw.h"

PlayerSprite::PlayerSprite()
{
	vec2 hullVerts[] = { { 0,3 },{ -2,-3 },{ 2,-3 } };
	collider = Collider(hullVerts, 3);

	transform.scl = vec2{ 10,10 };
	rigidbody.drag = 1;

	speed = 500;
	maxSpeed = 1000;
	turnSpeed = 20.f;

	vertThrust = 0;
	horizThrust = 0;
}

PlayerSprite::~PlayerSprite()
{
}

void PlayerSprite::doThrust(float val)
{
	vertThrust += val;
}

void PlayerSprite::doTurn(float val)
{
	horizThrust += val;
}

void PlayerSprite::update(float deltaTime, const vec2 & movement, GameState & gs)
{
	//transform.pos = { sfw::getMouseX(), sfw::getMouseY() };
	rigidbody.integrate(transform, deltaTime);

	rigidbody.addForce(movement * speed * vertThrust);
	rigidbody.addTorque(turnSpeed * horizThrust);

	rigidbody.integrate(transform, deltaTime);

	collider.hull = rotationDegrees(transform.rotAngle) * collider.hull;

	//make it not go
	rigidbody.addForce(-rigidbody.velocity);
	horizThrust = vertThrust = 0;
}

void PlayerSprite::draw(const mat3 & camera)
{

	collider.Draw(camera, transform, team.color);
	rigidbody.debugDraw(transform, camera);
}
