#include "GameState.h"
#include "ObjectCollision.h"


GameState::GameState()
{
}


GameState::~GameState()
{
}

void GameState::play()
{
	player.transform.pos = vec2{ 200,200 };
	player.transform.rotAngle = 0;

	asteroid[0].transform.pos = vec2{ 0,0 };
	asteroid[0].rigidbody.addImpulse(vec2{ 100,100 });
	asteroid[0].rigidbody.addTorque(24);

	asteroid[1].transform.pos = vec2{ 400,400 };
	asteroid[1].rigidbody.addImpulse(vec2{ -100,-100 });
	asteroid[1].rigidbody.addTorque(-24);
}

void GameState::update(float deltaTime)
{
	player.update(deltaTime, *this);
	camera.update(deltaTime, *this);

	for (int i = 0; i < 2; i++)
	{
		asteroid[i].update(deltaTime, *this);
		PlayerAsteroidCollision(player, asteroid[i]);
	}
		
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			AsteroidCollision(asteroid[i], asteroid[j]);
		}
	}
}

void GameState::draw()
{
	mat3 cam = camera.getCameraMatrix();
	player.draw(cam);

	for (int i = 0; i < 2; i++)
		asteroid[i].draw(cam);
}
