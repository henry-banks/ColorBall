#pragma once
#include "State.h"
#include "PlayerShip.h"
#include "Camera.h"
#include "Asteroid.h"
#include "PlayerBall.h"
#include "CaptureBall.h"
#include "Boundary.h"
#include "GameInstance.h"

#include <string>
#include <vector>

#include <Windows.h>

using namespace std;
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
	//Jamming this into an init function to tidy up the constructors
	void baseInit(int W_a, int H_a, int xBound_a, int yBound_a);

public:
	GameState(int W_a = 600, int H_a = 600);
	GameState(unsigned inFont, int W_a = 600, int H_a = 600);
	GameState(std::string inTitle, unsigned inFont, int W_a = 600, int H_a = 600);
	GameState(std::string inTitle, unsigned inFont, int W_a = 600, int H_a = 600, int xBound_a = 600, int yBound_a = 600);
	~GameState();

	PlayerShip			player;
	Camera				camera;
	PlayerBall			ball;
	vector<CaptureBall>	cap;
	Boundary			bounds[4];

	//Used to lock cursor to screen
	bool cursorLock;
	bool isWin;
	float lockTimer;	//Timer to prevent toggle spam
	int W, H;
	//Right-most and upper-most extents of the playing field (not the screen);
	int xBound, yBound;
	string title;		//Used for clipping cursor
	GameInstance instance;

	HWND hwnd;
	POINT cursorPos[1];
	bool releaseCursor;
	float releaseTimer;

	//Required because of base class
	void play();
	void play(GameInstance instance);
	void tick();
	void tick(float deltaTime, vec2 &cam);
	void draw();

	EState next();
};

