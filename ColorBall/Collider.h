#pragma once
#include "Shapes.h"
#include "Transform.h"
#include "RigidBody.h"
#include "collision.h"

class Collider
{
public:
	Collider();
	Collider(const vec2 *verts, int size);
	~Collider();

	AABB box;
	Hull hull;

	void DebugDraw(const mat3 &t, const Transform &trans);
};

CollisionData ColliderCollision(const Transform &aT, const Collider &aC,
								const Transform &bT, const Collider &bC);

CollisionData StaticResolution(Transform &aT, RigidBody &aR, const Collider &aC,
							  Transform &bT, const Collider &bC, float bounciness = 1);
CollisionData DynamicResolution(Transform &aT, RigidBody &aR, const Collider &aC,
							   Transform &bT, RigidBody &bR, const Collider &bC, float bounciness = 1);