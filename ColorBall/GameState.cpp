#include "GameState.h"
#include "ObjectCollision.h"
#include "shapedraw.h"
#include "sfwdraw.h"
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace sfw;

GameState::GameState(float W_a, float H_a)
{
	W = W_a;
	H = H_a;

	xBound = yBound = 600;

	min = vec2{ 0,0 };
	max = vec2{ W,H };

	releaseCursor = false;
	releaseTimer = 0.f;

	/*
	vec2 b1[] = { {xBound, yBound}, {-xBound, yBound} };
	bounds[0] = Collider( b1, 2 );	//Upper boundary

	vec2 b2[] = { {xBound, -yBound}, {-xBound, -yBound} };
	bounds[1] = Collider(b2, 2);	//Lower boundary

	vec2 b3[] = { {xBound, yBound}, {xBound, -yBound} };
	bounds[2] = Collider(b3, 2);	//Right boundary

	vec2 b4[] = { {-xBound, yBound}, {-xBound, -yBound} };
	bounds[3] = Collider(b4, 2);	//Left boundary
	*/
	
	//Initializing boundaries
	vec2 b1[] = { {xBound, yBound}, {-xBound, yBound} };
	bounds[0] = Boundary( b1, true );	//Upper boundary

	vec2 b2[] = { {xBound, -yBound}, {-xBound, -yBound} };
	bounds[1] = Boundary(b2, false);	//Lower boundary

	vec2 b3[] = { {xBound, yBound}, {xBound, -yBound} };
	bounds[2] = Boundary(b3, true);	//Right boundary

	vec2 b4[] = { {-xBound, yBound}, {-xBound, -yBound} };
	bounds[3] = Boundary(b4, false);	//Left boundary

	camera = Camera(W/2, H/2);
	nextState = EState::GAME;
	movement = { W / 2, H / 2 };
}

GameState::GameState(unsigned inFont, float W_a, float H_a)
{
	W = W_a;
	H = H_a;

	xBound = yBound = 600;

	min = vec2{ 0,0 };
	max = vec2{ W,H };

	//Initializing boundaries
	vec2 b1[] = { { xBound, yBound },{ -xBound, yBound } };
	bounds[0] = Boundary(b1, true);	//Upper boundary

	vec2 b2[] = { { xBound, -yBound },{ -xBound, -yBound } };
	bounds[1] = Boundary(b2, false);	//Lower boundary

	vec2 b3[] = { { xBound, yBound },{ xBound, -yBound } };
	bounds[2] = Boundary(b3, true);	//Right boundary

	vec2 b4[] = { { -xBound, yBound },{ -xBound, -yBound } };
	bounds[3] = Boundary(b4, false);	//Left boundary

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

	xBound = yBound = 600;

	min = vec2{ 0 - (W/2),0 - (H/2) };
	max = vec2{ W - (W / 2),H - (H / 2) };

	//Initializing boundaries
	vec2 b1[] = { { xBound, yBound },{ -xBound, yBound } };
	bounds[0] = Boundary(b1, true);	//Upper boundary

	vec2 b2[] = { { xBound, -yBound },{ -xBound, -yBound } };
	bounds[1] = Boundary(b2, false);	//Lower boundary

	vec2 b3[] = { { xBound, yBound },{ xBound, -yBound } };
	bounds[2] = Boundary(b3, true);	//Right boundary

	vec2 b4[] = { { -xBound, yBound },{ -xBound, -yBound } };
	bounds[3] = Boundary(b4, false);	//Left boundary

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

	xBound = yBound = 600;

	min = inMin;
	max = inMax;

	//Initializing boundaries
	vec2 b1[] = { { xBound, yBound },{ -xBound, yBound } };
	bounds[0] = Boundary(b1, true);	//Upper boundary

	vec2 b2[] = { { xBound, -yBound },{ -xBound, -yBound } };
	bounds[1] = Boundary(b2, false);	//Lower boundary

	vec2 b3[] = { { xBound, yBound },{ xBound, -yBound } };
	bounds[2] = Boundary(b3, true);	//Right boundary

	vec2 b4[] = { { -xBound, yBound },{ -xBound, -yBound } };
	bounds[3] = Boundary(b4, false);	//Left boundary

	releaseCursor = false;
	releaseTimer = 0.f;

	camera = Camera(W / 2, H / 2);
	nextState = EState::GAME;
	font = inFont;
	title = inTitle;
	movement = { W / 2, H / 2 };
}

GameState::GameState(vec2 inMin, vec2 inMax, std::string inTitle, unsigned inFont, float W_a, float H_a, float xBound_a, float yBound_a)
{
	W = W_a;
	H = H_a;

	xBound = xBound_a;
	yBound = yBound_a;

	//Initializing boundaries
	vec2 b1[] = { { xBound, yBound },{ -xBound, yBound } };
	bounds[0] = Boundary(b1, true);	//Upper boundary

	vec2 b2[] = { { xBound, -yBound },{ -xBound, -yBound } };
	bounds[1] = Boundary(b2, false);	//Lower boundary

	vec2 b3[] = { { xBound, yBound },{ xBound, -yBound } };
	bounds[2] = Boundary(b3, true);	//Right boundary

	vec2 b4[] = { { -xBound, yBound },{ -xBound, -yBound } };
	bounds[3] = Boundary(b4, false);	//Left boundary

	min = inMin;
	max = inMax;

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

	player.team.color = CYAN;
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

	GetCursorPos(cursorPos);
	float turnAngle = 0;

	if ((cursorPos[0].x != midX || cursorPos[0].y != midY) && !releaseCursor)
	{
		//Get turn angle using distance between center of screen and the mouse's X and Y.
		vec2 mousePos = { cursorPos[0].x, cursorPos[0].y };
		vec2 mid = { midX, midY };

		if (mousePos.x > mid.x)
			turnAngle = -dist(mid, mousePos);
		else if (mousePos.x < mid.x)
			turnAngle = dist(mid, mousePos);

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


	///////////////
	//RESET BUTTON
	///////////////
	if (getKey('Q'))
	{
		player.transform.pos = vec2{ 0,0 };
		player.rigidbody.velocity = vec2{ 0,0 };
		movement = vec2{ 0,0 };
		cam = vec2{ 0,0 };
	}

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

	//Boundary Collision
	for (int i = 0; i < 4; i++)
	{
		//StaticBoundCollision(bounds[i], player.transform, player.rigidbody);
		BoundCollision(player.transform, player.rigidbody, player.collider, bounds[i], .6);
		for (int j = 0; j < 2; j++)
			BoundCollision(ball[j].transform, ball[j].rigidbody, ball[j].collider, bounds[i], .8);
			//StaticBoundCollision(bounds[i], ball[i].transform, ball[i].rigidbody);
		for (int j = 0; j < 4; j++)
			BoundCollision(cap[j].transform, cap[j].rigidbody, cap[j].collider, bounds[i], .8);
			//StaticBoundCollision(bounds[i], cap[i].transform, cap[i].rigidbody);
	}	
	
	
	////////////////////////////
	//Actual updating of things
	////////////////////////////
	for (int i = 0; i < 2; i++)
		ball[i].update(deltaTime, *this);

	for (int i = 0; i < 4; i++)
		cap[i].update(deltaTime, *this);

	cam = player.transform.pos;
	player.update(deltaTime, turnAngle, player.transform.rotAngle);
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
		
	printf("%f", fabsf(round(fmodf(player.transform.rotAngle + 90, 360))));
	printf("\n");
	
	//Print boundaries (debug)
	for (int i = 0; i < 4; i++)
	{
		cap[i].draw(cam);
		bounds[i].collider.StaticDraw(cam, CYAN);
	}
}

EState GameState::next()
{
	if(isWin)
		nextState = EState::ENTER_END;
	return nextState;
}
