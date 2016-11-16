#include "RigidBody.h"
#include "sfwdraw.h"

using namespace sfw;

RigidBody::RigidBody()
{
	mass = 1.0f;
	drag = .25f;
	angDrag = 1.f;

	force = vec2{ 0,0 };
	impulse = vec2{ 0,0 };
	acc = vec2{ 0,0 };
	velocity = vec2{ 0,0 };

	force = vec2{ 0,0 };
	impulse = vec2{ 0,0 };
	torque = 0;

	angVel = 0.0f;
	angAcc = 0.0f;
}


RigidBody::~RigidBody()
{
}

void RigidBody::addForce(const vec2 & inForce)
{
	force += inForce;
}

void RigidBody::addImpulse(const vec2 & inImpulse)
{
	impulse += inImpulse;
}

void RigidBody::addTorque(float inTorque)
{
	torque += inTorque;
}

void RigidBody::integrate(Transform & trans, float deltaTime)
{
	//Magic math
	acc = force / mass;
	velocity += acc*deltaTime + impulse / mass;
	trans.pos += velocity * deltaTime;
	force = impulse = { 0,0 };

	//Drag/Dampening
	force = -velocity * drag;

	angAcc = torque / mass;
	angVel += angAcc * deltaTime;
	trans.rotAngle += angVel * deltaTime;

	torque = 0;

	torque = -angVel * angDrag;	
}

void RigidBody::debugDraw(const Transform & trans, const mat3 & t)
{
	vec2 p = (t * trans.getGlobalTransform()).c[2].xy;
	vec2 v = p + velocity;
	vec2 a = acc + p;

	//Velocity
	drawLine(p.x, p.y, v.x, v.y, CYAN);
	//Acceleration
	drawLine(p.x, p.y, a.x, a.y, MAGENTA);
}
