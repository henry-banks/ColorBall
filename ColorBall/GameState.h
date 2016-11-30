#pragma once
#include "State.h"
#include "PlayerShip.h"
#include "Camera.h"
#include "Asteroid.h"
#include "PlayerBall.h"
#include "CaptureBall.h"
#include "Boundary.h"
#include <string>

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
	GameState(std::string inTitle, unsigned inFont, float W_a = 600, float H_a = 600);
	GameState(vec2 inMin, vec2 inMax, std::string inTitle, unsigned inFont, float W_a = 600, float H_a = 600);
	~GameState();

	PlayerShip		player;
	Camera			camera;
	PlayerBall		ball[2];
	CaptureBall		cap[4];
	Boundary		bounds[4];
	//Defines lower-right(min) and upper-right(max) boundary corners
	vec2 min, max;

	//Used to lock cursor to screen
	bool cursorLock;
	bool isWin;
	float lockTimer;	//Timer to prevent toggle spam
	float W, H;
	std::string title;	//No title should be over 100 letters
	vec2 movement;		//Used to move cursor

	HWND hwnd;
	POINT cursorPos[1];
	bool releaseCursor;
	float releaseTimer;

	void play();
	void tick();
	void tick(float deltaTime, vec2 &cam);
	void draw();

	EState next();
};

