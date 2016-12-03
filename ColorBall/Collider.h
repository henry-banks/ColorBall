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
	void Draw(const mat3 &t, const Transform &trans, unsigned color);
	void StaticDraw(const mat3 &t, unsigned color);	//Used for drawing boundaries and other static colliders
};

CollisionData ColliderCollision(const Transform &aT, const Collider &aC,
								const Transform &bT, const Collider &bC);

CollisionData StaticResolution(Transform &aT, RigidBody &aR, const Collider &aC,
							   Transform &bT, const Collider &bC, float bounciness = 1);
CollisionData DynamicResolution(Transform &aT, RigidBody &aR, const Collider &aC,
							    Transform &bT, RigidBody &bR, const Collider &bC, float bounciness = 1);



//Special type of DynamicResolution specifically for player and ball
CollisionData BallResolution(Transform &aT, RigidBody &aR, const Collider &aC,
							 Transform &bT, RigidBody &bR, const Collider &bC, float bounciness = 1);