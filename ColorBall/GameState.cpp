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

	min = vec2{ 0,0 };
	max = vec2{ W,H };

	//Lower bound
	bounds[0] = Boundary(min.x, min.y, max.x, min.y, false);
	//Upper bound
	bounds[1] = Boundary(min.x, max.y, max.x, max.y, false);

	bounds[2] = Boundary(bounds[0].collider.hull.vertices[0].x, bounds[0].collider.hull.vertices[0].y, bounds[0].collider.hull.vertices[0].x, bounds[1].collider.hull.vertices[0].y, true);
	////Right bound
	//bounds[2] = Boundary(min.x, min.y, min.x, max.y, true);
	////Left bound
	//bounds[3] = Boundary(max.x, min.y, max.x, max.y, true);

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

	min = vec2{ 0,0 };
	max = vec2{ W,H };

	//Lower bound
	bounds[0] = Boundary(min.x, min.y, max.x, min.y, false);
	//Upper bound
	bounds[1] = Boundary(min.x, max.y, max.x, max.y, false);
	//Right bound
	bounds[2] = Boundary(min.x, min.y, min.x, max.y, true);
	//Left bound
	bounds[3] = Boundary(max.x, min.y, max.x, max.y, true);

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

	min = vec2{ 0 - (W/2),0 - (H/2) };
	max = vec2{ W - (W / 2),H - (H / 2) };

	//Lower bound
	bounds[0] = Boundary(min.x, min.y, max.x, min.y, false);
	//Upper bound
	bounds[1] = Boundary(min.x, max.y, max.x, max.y, false);
	//Right bound
	bounds[2] = Boundary(min.x, min.y, min.x, max.y, true);
	//Left bound
	bounds[3] = Boundary(max.x, min.y, max.x, max.y, true);

	releaseCursor = false;
	releaseTimer = 0.f;

	camera = Camera(W / 2, H / 2);
	nextState = EState::GAME;
	font = inFont;
	title = inTitle;
	movement = { W / 2, H / 2 };
}

GameState::GameState(vec2 inMin, vec2 inMax, std::string inTitle, unsigned inFont, float W_a, float H_a)
{
	W = W_a;
	H = H_a;

	min = inMin;
	max = inMax;
	
	//Upper bound
	bounds[0] = Boundary(min.x, max.y, max.x, max.y, false);
	//Lower bound
	bounds[1] = Boundary(min.x, min.y, max.x, min.y, false);
	//Left bound
	bounds[2] = Boundary(min.x, min.y, min.x, max.y, true);
	//Right bound
	bounds[3] = Boundary(max.x, min.y, max.x, max.y, true);

	releaseCursor = false;
	releaseTimer = 0.f;

	camera = Camera(W / 2, H / 2);
	nextState = EState::GAME;
	font = inFont;
	title = inTitle;
	movement = { W / 2, H / 2 };
}

GameState::~GameState()
{
}

void GameState::play()
{
	srand(time(0));
	SetCursorPos(player.transform.pos.x, player.transform.pos.y);
	GetCursorPos(cursorPos);

	nextState = EState::GAME;

	isWin = false;
	cursorLock = false;
	lockTimer = 0.f;
	releaseTimer = 0.f;

	player.team.color = 0x00e0ef;
	player.team.teamNum = 1;

	player.transform.pos = vec2{ 0,0 };
	player.transform.rotAngle = 0;

	ball[0].transform.pos = vec2{ -400,-400 };
	ball[0].rigidbody.addImpulse(vec2{ 1,1 });
	ball[0].team = player.team;
	//asteroid[0].rigidbody.addTorque(24);

	ball[1].transform.pos = vec2{ 400,400 };
	ball[1].rigidbody.addImpulse(vec2{ -1,-1 });
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
	///////////////
	//Check for win
	///////////////
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


	/////////////////////////////////
	//Mouse input (for turning ship)
	/////////////////////////////////

	//Update width and height (in case the window is moved)
	RECT rect;

	hwnd = FindWindow(0, "ColorBall");
	GetWindowRect(hwnd, &rect);

	float midX = rect.left + (W / 2);
	float midY = rect.top + (H / 2);

	//printf("Left: %d\nRight: %d\nTop: %d\nBottom: %d\n\n", rect.left, rect.right, rect.top, rect.bottom);

	GetCursorPos(cursorPos);
	float turnAngle = 0;

	if ((cursorPos[0].x != midX || cursorPos[0].y != midY) && !releaseCursor)
	{
		//Get turn angle using distance between center of screen and the mouse's X and Y.
		vec2 mousePos = { cursorPos[0].x, cursorPos[0].y };
		vec2 mid = { midX, midY };

		if (mousePos.x > mid.x)
			turnAngle = -dist(mid, mousePos); //angle(delta(mid, mousePos));
		else if (mousePos.x < mid.x)
			turnAngle = dist(mid, mousePos);//-angle(delta(mid, mousePos));

		//printf("Mid: %f, %f.  Mouse: %f, %f.  %f\n", mid.x, mid.y, mousePos.x, mousePos.y, turnAngle);

		SetCursorPos(midX, midY);	
	}
	

	/////////////////////
	//Cursor lock/unlock
	/////////////////////
	if (getKey('R') && releaseTimer <= 0)
	{
		//Flip-flop releaseCursor
		releaseCursor = releaseCursor ? false : true;
		SetCursorPos(midX, midY);
		releaseTimer = .5f;
	}
	if (releaseTimer >= 0)
		releaseTimer -= deltaTime;

	/////////////////////
	//Collision Checking
	/////////////////////
	for (int i = 0; i < 2; i++)
	{
		PlayerBallCollision(player, ball[i]);
		for (int j = 0; j < 2; j++)
			BallCollision(ball[i], ball[j]);
	}

	for (int i = 0; i < 4; i++)
	{
		cap[i].update(deltaTime, *this);
		for (int j = 0; j < 2; j++)
			BallPointCollision(ball[j], cap[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		BoundCollision(player.transform, player.rigidbody, player.collider, bounds[i]);

		for (int j = 0; j < 2; j++)
			BoundCollision(ball[j].transform, ball[j].rigidbody, ball[j].collider, bounds[i]);

		for (int j = 0; j < 4; j++)
			BoundCollision(cap[j].transform, cap[j].rigidbody, cap[j].collider, bounds[i]);
	}
	////////////////////////////
	//Actual updating of things
	////////////////////////////
	for (int i = 0; i < 2; i++)
		ball[i].update(deltaTime, *this);

	for (int i = 0; i < 4; i++)
		cap[i].update(deltaTime, *this);

	player.update(deltaTime, turnAngle);
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

	for (int i = 0; i < 2; i++) {
		printf("%d: %f, %f\n", i, ball[i].transform.pos.x, ball[i].transform.pos.y);
		ball[i].draw(cam);
	}
		
	printf("\n");
	for (int i = 0; i < 4; i++)
	{
		cap[i].draw(cam);
		bounds[i].debugDraw(cam);
	}		
}

EState GameState::next()
{
	if(isWin)
		nextState = EState::ENTER_END;
	return nextState;
}
