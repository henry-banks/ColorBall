#include "PlayerSprite.h"
#include "sfwdraw.h"
#include "shapedraw.h"

using namespace sfw;
using namespace spd;

PlayerSprite::PlayerSprite()
{
	vec2 hullVerts[] = { {0,3}, {-3,-3},{3,-3} };
	collider = Collider(hullVerts, 3);

	transform.scl = vec2{ 5,5 };
	color = 0xddddddff;
}


PlayerSprite::~PlayerSprite()
{
}

void PlayerSprite::update(float deltaTime, const vec2 &movement, GameState & gs)
{
	/*vec2 diff = transform.pos - movement;

	rigidbody.addForce(diff);
	rigidbody.addTorque(angleBetween(transform.pos, movement));*/

	rigidbody.integrate(transform, deltaTime);
}

void PlayerSprite::draw(const mat3 & camera)
{
	mat3 glob = camera * transform.getGlobalTransform();

	drawHull(glob * collider.hull, team.color);

	rigidbody.debugDraw(transform, camera);
	//collider.DebugDraw(camera, transform);
}
