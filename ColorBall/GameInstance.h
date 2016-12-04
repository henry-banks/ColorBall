#pragma once
#include "sfwdraw.h"

//Used to store data from options
struct GameInstance
{
	//Number of CaptureBalls
	int ballNum = 4;
	//Player color and enemy color (if enemies are used)
	unsigned color1 = CYAN, color2 = WHITE;
	//Whether or not there is a time limit
	bool isTimed = true;
	//How long (in seconds) a timed round will be.
	int timeLimit = 300;
	//Dimensions of the playing field
	int width = 1000, height = 1000;
};

