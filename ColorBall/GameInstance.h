#pragma once
#include "sfwdraw.h"
using namespace sfw;

//Used to store data from options
struct GameInstance
{
	//Number of CaptureBalls
	int ballNum = 4;
	//Player color and enemy color (if enemies are used)
	unsigned color1 = CYAN, color2 = WHITE;
	//Whether or not there is a time limit
	bool isTimed = true;
	//How long (in minutes) a timed round will be.
	int timeLimit = -1;
	//Dimensions of the playing field, not the screen
	int width = 500, height = 500;

	unsigned font = loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned cursor = loadTextureMap("./res/ball.png");
	unsigned clickedCursor = loadTextureMap("./res/ball_clicked.png");
};