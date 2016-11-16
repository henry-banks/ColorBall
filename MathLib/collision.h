#pragma once
#include "Shapes.h"

//Collision stuff

//1-dimensional collision (points on a line)
struct CollisionData1D
{
	float penDepth;		//Penetration Depth - How much overlap
	float colNormal;	//Collision Normal - -1 or 1
	float MTV;			//Minimum Translation Normal - penDepth - colNormal;

	bool result() const;
};

CollisionData1D collisionDetection1D(float aMin, float aMax, float bMin, float bMax);

struct SweptCollisionData1D
{
	float entryTime, exitTime;
	float colNormal;

	bool result() const;
};

SweptCollisionData1D sweptDetection1D(float aMin, float aMax, float aVel,
									  float bMin, float bMax, float bVel);


struct CollisionData
{
	//Penetration depth
	float penDepth;
	//Collision normal
	vec2 colNormal;

	//Minimum Translation Vector
	vec2 MTV() const;
	bool result() const;
};

CollisionData boxCollision(const AABB &a, const AABB &b);


struct CollisionDataSwept
{
	//Penetration depth
	float entryTime, exitTime;
	//Collision normal
	vec2 colNormal;

	bool result() const;
};

CollisionDataSwept boxCollisionSwept(const AABB &a, const vec2 &dA,
						   const AABB &b, const vec2 &dB);

CollisionData planeBoxCollision(const Plane &p, const AABB &b);
CollisionDataSwept planeBoxCollisionSwept(const Plane &p, const vec2 &pVel,
										   const AABB &b, const vec2 &bVel);

CollisionData HullCollision(const Hull &a, const Hull &b);
CollisionDataSwept HullCollisionSwept(const Hull &a, const vec2 &dA, const Hull &b, const vec2 &db);

//For quickly evaluating groups of hulls
CollisionData HullCollisionGroup(const Hull a[], unsigned aSize, const Hull b[], unsigned bSize);