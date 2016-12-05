#pragma once
#include "sfwdraw.h"
#include "State.h"
#include "MenuButton.h"
#include "GameInstance.h"

using namespace sfw;

class MenuState : public State
{
	MenuButton playButton;
	MenuButton aboutButton;
	MenuButton optionButton;
	MenuButton quitButton;

public:
	MenuState();
	MenuState(const GameInstance &instance, int W_a = 600, int H_a = 600);
	~MenuState();
	int font;
	int cursor, clickedCursor;
	float W, H;

	void play();
	void tick();
	void draw();

	EState next();
};

