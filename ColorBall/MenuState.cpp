#include "MenuState.h"





MenuState::MenuState()
{
}

MenuState::MenuState(unsigned inFont, int W_a, int H_a)
{
	font = inFont;
	W = W_a;
	H = H_a;
	nextState = EState::MENU;

	playButton = MenuButton(font, W / 2 - 100, H - 250, 200, 50, WHITE, "Play", EState::ENTER_GAME);
	aboutButton = MenuButton(font, W / 2 - 100, H - 325, 200, 50, WHITE, "About", EState::MENU);
	quitButton = MenuButton(font, W / 2 - 100, H - 400, 200, 50, WHITE, "Quit", EState::TERMINATE);
}

MenuState::~MenuState()
{
}

void MenuState::play()
{
	nextState = EState::MENU;
}

void MenuState::tick()
{
	playButton.tick();
	aboutButton.tick();
	quitButton.tick();
}

void MenuState::draw()
{
	drawString(font, "ColorBall", W/2 - 135, H - 50, 30, 30, 0, '\0', WHITE);

	playButton.draw();
	aboutButton.draw();
	quitButton.draw();

	cursorDraw();
}

EState MenuState::next()
{
	if (playButton.isClicked)
	{
		playButton.isClicked = false;
		nextState = playButton.next();
	}
	else if (aboutButton.isClicked)
	{
		aboutButton.isClicked = false;
		nextState = aboutButton.next();
	}
	else if (quitButton.isClicked)
	{
		quitButton.isClicked = false;
		nextState = quitButton.next();
	}

	return nextState;
}
