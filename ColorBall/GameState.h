#pragma once
#include "State.h"
#include "PlayerShip.h"
#include "PlayerSprite.h"
#include "Camera.h"
#include "Asteroid.h"
#include "PlayerBall.h"
#include "CaptureBall.h"

#include <Windows.h>
/*
	INIT(ialize)
		- Called at application start
		- Used for loading resources like textures
	PLAY/EXEC/enter
		- Called once on transition to new state
		- Gets called to reset the logic of the state (ie. new game, reset timers)
	EXIT
		- Called on transition out of state
		- Not always useful, optional(?)
	TERM(inatie)
		- Called at application shutdown
		- Used to free up resources
	STEP/UPDATE/TICK
		- Called every frame
		- Used to update logic
	DRAW/RENDER
		- Called every frame
		- Used to draw stuff
	
	These are the six prime functions of game states.
*/


class GameState : public State
{
public:
	GameState(float W_a = 600, float H_a = 600);
	GameState(unsigned inFont, float W_a = 600, float H_a = 600);
	~GameState();

	PlayerSprite	player;
	Camera			camera;
	PlayerBall		asteroid[2];
	CaptureBall		cap[4];

	//Used to lock cursor to screen
	bool cursorLock;
	bool isWin;
	float lockTimer; //Timer to prevent toggle spam
	float W, H;

	POINT cursorPos[1];
	bool releaseCursor;
	float releaseTimer;

	void play();
	void tick();
	void tick(float deltaTime, const vec2 &movement, vec2 &cam);
	void draw();

	EState next();
};

