#pragma once
#include "State.h"
#include "MenuButton.h"
#include "GameInstance.h"

class EndState :
	public State
{
	MenuButton backButton;
	MenuButton quitButton;

	bool isWin;
	int font;
	int cursor, clickedCursor;
	int W, H;
public:
	EndState(int W_a, int H_a);
	~EndState();

	void play();
	void play(GameInstance instance, bool inIsWin);

	void draw();
	void tick();

	EState next();
};

