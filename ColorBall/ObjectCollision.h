#pragma once

#include "Asteroid.h"
#include "PlayerShip.h"
#include "PlayerShip.h"
#include "PlayerBall.h"
#include "CaptureBall.h"
#include "Boundary.h"

void PlayerAsteroidCollision(PlayerShip &player, Asteroid &as);

void AsteroidCollision(Asteroid &a1, Asteroid &a2);

void PlayerBallCollision(PlayerShip &player, PlayerBall &ball);
void BallCollision(PlayerBall &b1, PlayerBall &b2);
bool BallPointCollision(PlayerBall &ball, CaptureBall &p);

//General collision with boundary
void BoundCollision(Transform &trans, RigidBody & rigid, Collider &col, Boundary &bound);