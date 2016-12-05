#include "EndState.h"
#include "sfwdraw.h"
using namespace sfw;


EndState::EndState(int W_a, int H_a)
{
	W = W_a;
	H = H_a;

	nextState = END;
}


EndState::~EndState()
{
}

void EndState::play()
{
}

void EndState::play(GameInstance instance, bool inIsWin)
{
	font = instance.font;
	cursor = instance.cursor;
	clickedCursor = instance.clickedCursor;

	isWin = inIsWin;
	nextState = END;

	backButton = MenuButton(font, 75, 100, 200, 50, WHITE, "Menu", EState::ENTER_MENU);
	quitButton = MenuButton(font, W - 275, 100, 200, 50, WHITE, "Cancel", EXIT_OPTION);
}

void EndState::draw()
{
	if (isWin)
		drawString(font, "YOU WON!", (W / 2) - 120, (H / 2) + 100, 30, 30);
	else
		drawString(font, "YOU LOST!", (W / 2) - 120, (H / 2) + 115, 30, 30);

	backButton.draw();
	quitButton.draw();

	cursorDraw(cursor, clickedCursor);
}

void EndState::tick()
{
	backButton.tick();
	quitButton.tick();
}

EState EndState::next()
{
	if (backButton.isClicked)
	{
		backButton.isClicked = false;
		nextState = backButton.next();
	}
	else if (quitButton.isClicked)
	{
		quitButton.isClicked = false;
		nextState = quitButton.next();
	}

	return nextState;;
}
