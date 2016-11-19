#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "sfwdraw.h"
#include "GameState.h"
#include "flops.h"
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

	GameState game(W / 2, H / 2);
	game.play();

	//used to move player
	vec2 movement = { 0, 0 };
	vec2 cam = movement;

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

	bool releaseCursor = false;
	float releaseTimer = 0.f;

	bool isExit = false;

	while (stepContext() && !isExit)
	{
		float deltaTime = getDeltaTime();

		game.update(deltaTime, movement, cam);
		game.draw();

		if (getKey('Q'))
		{
			game.player.transform.pos = vec2{ 0,0 };
			game.player.rigidbody.velocity = vec2{ 0,0 };
			movement = vec2{ 0,0 };
			cam = vec2{ 0,0 };
		}

		//Show coordinates
		string xpos = to_string(game.player.transform.pos.x);
		string ypos = to_string(game.player.transform.pos.y);

		drawString(f, xpos.c_str(), 5, 20, 12, 12, 0, '\0', WHITE);
		drawString(f, ypos.c_str(), 175, 20, 12, 12, 0, '\0', WHITE);

		drawString(f, "Press E to exit\nPress R to toggle locked cursor", 0, H - 5, 16, 16, 0, '\0', WHITE);
		releaseCursor ? drawString(f, "OPEN", W / 2, H - 5, 16, 16, 0, '\0', GREEN) : drawString(f, "LOCKED", W / 2, H - 5, 16, 16, 0, '\0', RED);

		//Got most of this from the internet
		POINT cursorPos[1];
		GetCursorPos(cursorPos);

		movement = vec2{ cursorPos[0].x - (W / 2), (H / 2) - cursorPos[0].y };
		cam += movement;
		//printf("%f, %f\n", cursorPos[0].x, cursorPos[0].y);
		printf("%f, %f\n", cam.x, cam.y);

		if ((cursorPos[0].x != W / 2 || cursorPos[0].y != H / 2) && !releaseCursor)
		{
			RigidBody &r = game.player.rigidbody;
			//game.player.transform.pos += movement;
			float d = dist(game.player.transform.pos, cam);

			r.addForce(movement * (d/10));
			//r.velocity = cam - game.player.transform.pos;
			r.addTorque(angle(movement));
			SetCursorPos(W / 2, H / 2);
		}

		if (game.player.transform.pos != cam)
		{
			//t.rotAngle = angleBetween(t.pos, movement);
		}

		//game.player.transform.rotAngle += deltaTime;

		if (releaseTimer > 0)
			releaseTimer -= deltaTime;

		if (getKey('R') && releaseTimer <= 0)
		{
			//Flip-flop releaseCursor
			releaseCursor = releaseCursor ? false : true;
			SetCursorPos(W / 2, H / 2);
			releaseTimer = .5f;
		}

		if (getKey('E'))
		{
			isExit = true;
		}

		if (game.isWin)
			drawString(f, "YOU WON", W - W / 2, H /2 , 32, 32, 0, '\0', WHITE);

	}

	termContext();
}