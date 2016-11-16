#include "ObjectCollision.h"

void PlayerAsteroidCollision(PlayerShip & player, Asteroid & as)
{
	CollisionData out = DynamicResolution(player.transform, player.rigidbody, player.collider,
		as.transform, as.rigidbody, as.collider);

	if (out.penDepth >= 0)
		player.transform.scl *= .9f;
}

void AsteroidCollision(Asteroid & a1, Asteroid & a2)
{
	DynamicResolution(a1.transform, a1.rigidbody, a1.collider,
					  a2.transform, a2.rigidbody, a2.collider);
}
