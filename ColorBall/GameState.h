#pragma once
#include "PlayerShip.h"
#include "Camera.h"
#include "Asteroid.h"
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


class GameState
{
public:
	GameState();
	~GameState();

	PlayerShip	player;
	Camera		camera;
	Asteroid	asteroid[2];

	void play();
	void update(float deltaTime);
	void draw();
};

