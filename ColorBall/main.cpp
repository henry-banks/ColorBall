#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "sfwdraw.h"
#include "GameState.h"
#include "MenuState.h"
#include "AboutState.h"
#include "OptionState.h"
#include "GameInstance.h"
#include "flops.h"

//Make sure Windows.h is LAST
#include <Windows.h>

using namespace sfw;
using namespace std;


void main()
{
	float W = 1200, H = 800;
	char title[] = "ColorBall";
	initContext(W, H, title);
	setBackgroundColor(0x222222ff);

	SetCursorPos(W / 2, H / 2);

	unsigned f = loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned cursor = loadTextureMap("./res/ball.png");
	unsigned clickedCursor = loadTextureMap("./res/ball_clicked.png");
	
	GameInstance instance;

	GameState game = GameState(title, f, W, H, 500, 500);
	MenuState menu = MenuState(f, W, H);
	AboutState about = AboutState(f, cursor, clickedCursor, W, H);

	EState state = EState::ENTER_MENU;

	//used to move player
	vec2 cam = { 0,0 };

	bool isExit = false;

	while (stepContext() && !isExit)
	{
		float deltaTime = getDeltaTime();

		switch (state)
		{
		case ENTER_MENU:
			menu.play();
		case MENU:
			menu.tick();
			menu.draw();
			state = menu.next();
			break;

		case ENTER_ABOUT:
			about.play();
		case ABOUT:
			about.tick();
			about.draw();
			state = about.next();
			break;

		case ENTER_GAME:
			game.play(instance);
		case GAME:
			game.tick(deltaTime, cam);
			game.draw();
			state = game.next();
			break;

		case TERMINATE:
			isExit = true;
			break;
		}		

		//Universal quit key
		if (getKey('E'))
		{
			isExit = true;
		}

		if (game.isWin)
			drawString(f, "YOU WON", W - W / 2, H /2 , 32, 32, 0, '\0', WHITE);

	}

	termContext();
}