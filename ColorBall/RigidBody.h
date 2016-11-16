#pragma once

#include "vec2.h"
#include "mat3.h"	
#include "Transform.h"

class RigidBody
{
public:
	RigidBody();
	~RigidBody();

	float mass, drag, angDrag;

	vec2 force, impulse;
	vec2 velocity;
	//Angular Velocity
	float angVel;
	//Acceleration
	vec2 acc;
	float angAcc;
	float torque;

	void addForce(const vec2 &force);
	void addImpulse(const vec2 &impulse);
	void addTorque(float torque);
	
	void integrate(Transform &trans, float deltaTime);

	void debugDraw(const Transform &trans, const mat3 &t);
};

