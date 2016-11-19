#include "GameState.h"
#include "ObjectCollision.h"
#include "sfwdraw.h"
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace sfw;

GameState::GameState(int W, int H)
{
	camera = Camera(W, H);
}


GameState::~GameState()
{
}

void GameState::play()
{
	srand(time(0));

	isWin = false;

	cursorLock = false;
	lockTimer = 0.f;

	player.team.color = 0x00e0ef;
	player.team.teamNum = 1;

	player.transform.pos = vec2{ 0,0 };
	player.transform.rotAngle = 0;

	asteroid[0].transform.pos = vec2{ -400,-400 };
	asteroid[0].rigidbody.addImpulse(vec2{ 1,1 });
	asteroid[0].team = player.team;
	//asteroid[0].rigidbody.addTorque(24);

	asteroid[1].transform.pos = vec2{ 400,400 };
	asteroid[1].rigidbody.addImpulse(vec2{ -1,-1 });
	//asteroid[1].rigidbody.addTorque(-24);

	for (int i = 0; i < 4; i++)
	{
		float x = rand() % 800 - 400;
		float y = rand() % 800 - 400;

		cap[i].transform.pos = vec2{ x,y };
	}
}

void GameState::update(float deltaTime, const vec2 &movement, const vec2 &cam)
{
	for (int i = 0; i < 4; i++)
	{
		if (cap[i].team.teamNum != player.team.teamNum)
		{
			isWin = false;
			break;
		}
		isWin = true;
	}
	//If the player won, STOP EVERYTHING
	if (isWin)
		return;

	player.update(deltaTime, movement, *this);
	camera.update(deltaTime, cam, *this);

	for (int i = 0; i < 2; i++)
	{
		asteroid[i].update(deltaTime, *this);
		PlayerBallCollision(player, asteroid[i]);
	}
		
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			BallCollision(asteroid[i], asteroid[j]);
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			BallPointCollision(asteroid[j], cap[i]);
		}
	}

}

void GameState::draw()
{
	if (isWin)
		return;

	mat3 cam = camera.getCameraMatrix();
	player.draw(cam);

	for (int i = 0; i < 2; i++)
		asteroid[i].draw(cam);

	for (int i = 0; i < 4; i++)
		cap[i].draw(cam);
}
