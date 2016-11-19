#include "ObjectCollision.h"

void PlayerAsteroidCollision(PlayerShip & player, Asteroid & as)
{
	CollisionData out = DynamicResolution(player.transform, player.rigidbody, player.collider,
		as.transform, as.rigidbody, as.collider);

	//if (out.penDepth >= 0)
		//player.transform.scl *= .9f;
}

void AsteroidCollision(Asteroid & a1, Asteroid & a2)
{
	DynamicResolution(a1.transform, a1.rigidbody, a1.collider,
					  a2.transform, a2.rigidbody, a2.collider);
}

void PlayerBallCollision(PlayerSprite & player, PlayerBall & ball)
{
	DynamicResolution(player.transform, player.rigidbody, player.collider,
					  ball.transform, ball.rigidbody, ball.collider);
}

void BallCollision(PlayerBall & b1, PlayerBall & b2)
{
	DynamicResolution(b1.transform, b1.rigidbody, b1.collider,
					  b2.transform, b2.rigidbody, b2.collider);
}

bool BallPointCollision(PlayerBall & ball, CaptureBall & p)
{
	CollisionData out = ColliderCollision(ball.transform, ball.collider, p.transform, p.collider);

	if (out.penDepth >= 0)
	{
		p.team = ball.team;
		return true;
	}
	return false;
}
