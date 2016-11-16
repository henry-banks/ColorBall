#include "Collider.h"
#include "shapedraw.h"
#include "sfwdraw.h"
#include <math.h>

//shapedraw namespace
using namespace spd;

Collider::Collider()
{
}

// : hull(verts, size) calls constructor for the 'hull' variable (initializer)
Collider::Collider(const vec2 * verts, int size) : hull(verts, size)
{
	vec2 minv{ INFINITY, INFINITY };
	vec2 maxv{ -INFINITY, -INFINITY };

	//Find min and max vertices
	for (int i = 0; i < size; i++)
	{
		minv = min(minv, verts[i]);
		maxv = max(maxv, verts[i]);
	}

	//math-y math-ness
	box.pos = (minv + maxv) / 2;
	box.he = (maxv - minv) / 2;
}


Collider::~Collider()
{
}

void Collider::DebugDraw(const mat3 & t, const Transform & trans)
{
	mat3 glob = t * trans.getGlobalTransform();

	drawAABB(glob * box, RED);
	drawHull(glob * hull, BLUE);

}

CollisionData ColliderCollision(const Transform & aT, const Collider & aC, const Transform & bT, const Collider & bC)
{
	CollisionData out;

	out = boxCollision(aT.getGlobalTransform() * aC.box,
					   bT.getGlobalTransform() * bC.box);

	//If below is true, there's probably a collision
	//So, go on to the more expensive and accurate hull collision
	if(out.penDepth >=0)
		out = HullCollision(aT.getGlobalTransform() * aC.hull,
							bT.getGlobalTransform() * bC.hull);

	return out;
}

CollisionData StaticResolution(Transform & aT, RigidBody & aR, const Collider & aC, Transform & bT, const Collider & bC, float bounciness)
{
	CollisionData out = ColliderCollision(aT, aC, bT, bC);

	//If there is overlap, resolve collision
	if (out.penDepth >= 0)
	{
		//Minimum Translation Vector
		vec2 mtv = out.penDepth * out.colNormal;
		aT.pos -= mtv;

		aR.velocity = reflect(aR.velocity, out.colNormal) * bounciness;
	}

	return out;
}

CollisionData DynamicResolution(Transform & aT, RigidBody & aR, const Collider & aC, Transform & bT, RigidBody & bR, const Collider & bC, float bounciness)
{
	CollisionData out = ColliderCollision(aT, aC, bT, bC);

	if (out.penDepth >= 0)
	{
		////////////////////////////
		//CORRECTION

		//minimum translation vector
		vec2 mtv = out.penDepth * out.colNormal;

		//Magnitudes
		float am = magnitude(aR.mass * aR.velocity);
		float bm = magnitude(bR.mass * bR.velocity);
		float cm = am + bm;

		aT.pos -= mtv * (1 - am / cm);
		bT.pos += mtv * (1 - bm / cm);

		////////////////////////////
		//RESOLUTION

		vec2 &a = aR.velocity;
		float &p = aR.mass;
		
		vec2 &b = bR.velocity;
		float &q = aR.mass;
		
		//e = bounciness
		//a*p + b*q = x*p + y*q		: conservation of momentum
		//x-y = -e(a-b)				: liner collision

		//magic math....so much magic math
		vec2 x = (a*p + b*q + (-bounciness * (a - b))*q) / (q + p);
		vec2 y = bounciness * (a - b) + x;

		aR.velocity = x;
		bR.velocity = y;
	}

	return out;
}
