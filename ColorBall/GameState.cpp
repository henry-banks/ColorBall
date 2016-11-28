#include "GameState.h"
#include "ObjectCollision.h"
#include "sfwdraw.h"
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <Windows.h>

using namespace sfw;

GameState::GameState(float W_a, float H_a)
{
	W = W_a;
	H = H_a;

	releaseCursor = false;
	releaseTimer = 0.f;

	camera = Camera(W/2, H/2);
	nextState = EState::GAME;
}

GameState::GameState(unsigned inFont, float W_a, float H_a)
{
	W = W_a;
	H = H_a;

	releaseCursor = false;
	releaseTimer = 0.f;

	camera = Camera(W/2, H/2);
	nextState = EState::GAME;
	font = inFont;
}

GameState::~GameState()
{
}

void GameState::play()
{
	srand(time(0));
	GetCursorPos(cursorPos);

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

void GameState::tick()
{
}

void GameState::tick(float deltaTime, const vec2 &movement, vec2 &cam)
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
		asteroid[i].update(deltaTime, *this);
		for (int j = 0; j < 2; j++)
		{
			BallCollision(asteroid[i], asteroid[j]);
		}
	}


	//Got most of this from the internet
	for (int i = 0; i < 4; i++)
	{
		cap[i].update(deltaTime, *this);
		for (int j = 0; j < 2; j++)
		{
			BallPointCollision(asteroid[j], cap[i]);
		}
	}

	if ((cursorPos[0].x != W / 2 || cursorPos[0].y != H / 2) && !releaseCursor)
	{
		RigidBody &r = player.rigidbody;
		//game.player.transform.pos += movement;
		float d = dist(player.transform.pos, cam);

		r.addForce(movement * (d / 10));
		//r.velocity = cam - game.player.transform.pos;
		r.addTorque(angle(movement));
		SetCursorPos(W / 2, H / 2);
	}

	if (player.transform.pos != cam)
	{
		//t.rotAngle = angleBetween(t.pos, movement);
	}

	//game.player.transform.rotAngle += deltaTime;

	if (releaseTimer > 0)
		releaseTimer -= deltaTime;

	if (getKey('R') && releaseTimer <= 0)
	{
		//Flip-flop releaseCursor
		releaseCursor = releaseCursor ? false : true;
		SetCursorPos(W / 2, H / 2);
		releaseTimer = .5f;
	}

	cam += movement;

}

void GameState::draw()
{
	if (isWin)
		return;

	releaseCursor ? drawString(font, "OPEN", W / 2, H - 5, 16, 16, 0, '\0', GREEN) : drawString(font, "LOCKED", W / 2, H - 5, 16, 16, 0, '\0', RED);
	drawString(font, "Press E to exit\nPress R to toggle locked cursor", 0, H - 5, 16, 16, 0, '\0', WHITE);

	mat3 cam = camera.getCameraMatrix();
	player.draw(cam);

	for (int i = 0; i < 2; i++)
		asteroid[i].draw(cam);

	for (int i = 0; i < 4; i++)
		cap[i].draw(cam);
}

EState GameState::next()
{
	return nextState;
}
