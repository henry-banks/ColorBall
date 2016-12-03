#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "sfwdraw.h"
#include "GameState.h"
#include "MenuState.h"
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

	unsigned f = loadTextureMap("./fontmap.png", 16, 16);
	//
	GameState game = GameState(vec2{ -100,-100 }, vec2{ 100,100 }, title, f, W, H, 1000, 1000);
	game.play();
	MenuState menu = MenuState(f, W, H);

	EState state = EState::ENTER_MENU;

	//used to move player
	vec2 movement = { 0, 0 }; //remove?
	vec2 cam = { 0,0 };

	//Lock cursor to window
	/*HWND hwnd;
	hwnd = FindWindow(0, title);
	RECT r;
	GetWindowRect(hwnd, &r);
	r.left += 8;
	r.top += 31;
	r.right -= 7;
	r.bottom -= 7;
	ClipCursor(&r);
	Hide cursor
	ShowCursor(false);*/

	bool isExit = false;

	while (stepContext() && !isExit)
	{
		float deltaTime = getDeltaTime();

		switch (state)
		{
		case EState::ENTER_MENU:
			menu.play();
		case EState::MENU:
			menu.tick();
			menu.draw();
			state = menu.next();
			break;
		case EState::ENTER_GAME:
			game.play();
		case EState::GAME:
			game.tick(deltaTime, cam);
			game.draw();
			state = game.next();
			break;
		case EState::TERMINATE:
			isExit = true;
			break;
		}

		//Show coordinates
		string xpos = to_string(game.player.transform.pos.x);
		string ypos = to_string(game.player.transform.pos.y);

		drawString(f, xpos.c_str(), 5, 20, 12, 12, 0, '\0', WHITE);
		drawString(f, ypos.c_str(), 175, 20, 12, 12, 0, '\0', WHITE);
		
		//printf("%f, %f\n", cursorPos[0].x, cursorPos[0].y);
		//printf("%f, %f\n", cam.x, cam.y);
		

		if (getKey('E'))
		{
			isExit = true;
		}

		if (game.isWin)
			drawString(f, "YOU WON", W - W / 2, H /2 , 32, 32, 0, '\0', WHITE);

	}

	termContext();
}