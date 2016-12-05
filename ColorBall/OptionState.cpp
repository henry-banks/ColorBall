#include "OptionState.h"
#include "sfwdraw.h"
using namespace sfw;

OptionState::OptionState(GameInstance inInstance, int inFont, int inCursor, int inClickedCursor, int W_a, int H_a)
{
	font = inFont;

	cursor = inCursor;
	clickedCursor = inClickedCursor;

	instance = inInstance;
	
	W = W_a;
	H = H_a;

	confirmButton = MenuButton(font, 75, 100, 200, 50, WHITE, "Confirm", EXIT_OPTION);
	cancelButton = MenuButton(font, W - 275, 100, 200, 50, WHITE, "Cancel", EXIT_OPTION);
	defaultButton = MenuButton(font, (W / 2) - 100, 100, 200, 50, WHITE, "Defaults", OPTION);
}


OptionState::~OptionState()
{
}

void OptionState::play()
{
	nextState = OPTION;
}

void OptionState::play(GameInstance inInstance)
{
	instance = inInstance;

	ballOpt = OptionNum(font, "Number of point-balls", W - 200, H - 100, 50, WHITE, 1, instance.ballNum);
	heightOpt = OptionNum(font, "Height of playing field", W - 200, H - 175, 50, WHITE, 50, instance.height);
	widthOpt = OptionNum(font, "Width of playing field", W - 200, H - 250, 50, WHITE, 50, instance.width);
	timerOpt = OptionNum(font, "Playing time(in minutes).  Set to negative fo untimed.", W - 200, H - 325, 50, WHITE, 1, instance.timeLimit);

	nextState = OPTION;
}

void OptionState::draw()
{
	ballOpt.draw();
	widthOpt.draw();
	heightOpt.draw();
	timerOpt.draw();

	confirmButton.draw();
	cancelButton.draw();
	defaultButton.draw();

	drawString(font, "OPTIONS", (W / 2) - 120, H - 25, 30, 30);

	cursorDraw(cursor, clickedCursor);
}

void OptionState::tick()
{
}

void OptionState::tick(float deltaTime)
{
	ballOpt.tick(deltaTime);
	widthOpt.tick(deltaTime);
	heightOpt.tick(deltaTime);
	timerOpt.tick(deltaTime);

	confirmButton.tick();
	cancelButton.tick();
	defaultButton.tick();
	if (defaultButton.isClicked)
	{
		defaultButton.isClicked = false;	
		instance = GameInstance();
		play(instance);
	}
}

void OptionState::apply()
{
	instance.ballNum = ballOpt.getNum();
	instance.width = widthOpt.getNum();
	instance.height = heightOpt.getNum();
	instance.timeLimit = timerOpt.getNum();
}

GameInstance OptionState::getInstance()
{
	return instance;
}

EState OptionState::next()
{
	if (confirmButton.isClicked)
	{
		confirmButton.isClicked = false;
		apply();
		nextState = confirmButton.next();
	}

	else if (cancelButton.isClicked)
	{
		cancelButton.isClicked = false;
		nextState = cancelButton.next();
	}

	return nextState;
}
