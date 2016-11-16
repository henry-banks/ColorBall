#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "sfwdraw.h"
#include "GameState.h"

using namespace sfw;
using namespace std;


void main()
{
	float W = 1600, H = 1000;
	initContext(W, H);
	setBackgroundColor(0x222222ff);

	unsigned f = loadTextureMap("./fontmap.png", 16, 16);

	GameState game;

	game.play();

	while (stepContext())
	{
		float deltaTime = getDeltaTime();

		game.update(deltaTime);
		game.draw();

		if (getKey('Q'))
		{
			game.player.transform.pos = vec2{ 0,0 };
		}

		//Show coordinates
		string xpos = to_string(game.player.transform.pos.x);
		string ypos = to_string(game.player.transform.pos.y);

		drawString(f, xpos.c_str(), 5, 20, 12, 12, 0, '\0', WHITE);
		drawString(f, ypos.c_str(), 175, 20, 12, 12, 0, '\0', WHITE);

	}

	sfw::termContext();
}