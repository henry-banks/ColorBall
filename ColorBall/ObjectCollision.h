#pragma once

#include "Asteroid.h"
#include "PlayerShip.h"
#include "PlayerSprite.h"
#include "PlayerBall.h"
#include "CaptureBall.h"

void PlayerAsteroidCollision(PlayerShip &player, Asteroid &as);

void AsteroidCollision(Asteroid &a1, Asteroid &a2);

void PlayerBallCollision(PlayerSprite &player, PlayerBall &ball);
void BallCollision(PlayerBall &b1, PlayerBall &b2);
bool BallPointCollision(PlayerBall &ball, CaptureBall &p);