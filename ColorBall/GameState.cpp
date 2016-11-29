#include "GameState.h"
#include "ObjectCollision.h"
#include "sfwdraw.h"
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace sfw;

GameState::GameState(float W_a, float H_a)
{
	W = W_a;
	H = H_a;

	releaseCursor = false;
	releaseTimer = 0.f;

	camera = Camera(W/2, H/2);
	nextState = EState::GAME;
	movement = { W / 2, H / 2 };
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
	movement = { W / 2, H / 2 };
}

GameState::GameState(std::string inTitle, unsigned inFont, float W_a, float H_a)
{
	W = W_a;
	H = H_a;

	releaseCursor = false;
	releaseTimer = 0.f;

	camera = Camera(W / 2, H / 2);
	nextState = EState::GAME;
	font = inFont;
	title = inTitle;
	movement = { W / 2, H / 2 };

	hwnd = FindWindow(0, title.c_str());
}

GameState::~GameState()
{
}

void GameState::play()
{
	srand(time(0));
	SetCursorPos(player.transform.pos.x, player.transform.pos.y);
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
		cap[i].transform.rotAngle = rand();
	}
}

void GameState::tick()
{
}

void GameState::tick(float deltaTime, vec2 &cam)
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
	
	GetCursorPos(cursorPos);

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


	for (int i = 0; i < 4; i++)
	{
		cap[i].update(deltaTime, *this);
		for (int j = 0; j < 2; j++)
		{
			BallPointCollision(asteroid[j], cap[i]);
		}
	}

	player.update(deltaTime, movement, *this);
	camera.update(deltaTime, cam, *this);
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
