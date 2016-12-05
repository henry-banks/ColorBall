#include "AboutState.h"
#include "sfwdraw.h"
using namespace sfw;

AboutState::AboutState(int inW, int inH)
{
	W = inW;
	H = inH;
}

AboutState::AboutState(int inFont, int inCursor, int inClickedCursor, int inW, int inH)
{
	font = inFont;
	cursor = inCursor;
	clickedCursor = inClickedCursor;
	backButton = MenuButton(font, 75, 100, 200, 50, WHITE, "Back", EState::ENTER_MENU);

	W = inW;
	H = inH;
}

AboutState::~AboutState()
{
}

void AboutState::play()
{
	//nothing here
}

void AboutState::draw()
{
	drawString(font, "Colorball", 75, H - 50, 30, 30, 0, '\0');

	drawString(font, "Controls: WASD to move.  Use mouse to turn.", 75, H - 100, 15, 15, 0, '\0');
	drawString(font, "Hold Space to brake, Hold F to go Fast. ", 75, H - 120, 15, 15, 0, '\0');
	drawString(font, "Press E to exit, press R while in-game to", 75, H - 140, 15, 15, 0, '\0');
	drawString(font, "release the cursor.", 75, H - 160, 15, 15, 0, '\0');
	drawString(font, "Instructions: Run into the big ball to hit it.", 75, H - 200, 15, 15, 0, '\0');
	drawString(font, "When the big ball hits one of the little", 75, H - 220, 15, 15, 0, '\0');
	drawString(font, "balls, it will turn to your color.  Turn all", 75, H - 240, 15, 15, 0, '\0');
	drawString(font, "the balls to your color to win.", 75, H - 260, 15, 15, 0, '\0');

	drawString(font, "Programming: Henry Banks", 75, H - 300, 20, 20, 0, '\0');
	drawString(font, "\"Art\": Henry Banks", 75, H - 320, 20, 20, 0, '\0');
	drawString(font, "Design: Henry Banks", 75, H - 340, 20, 20, 0, '\0');
	drawString(font, "All Other Jobs: Henry Banks", 75, H - 360, 20, 20, 0, '\0');

	backButton.draw();

	cursorDraw(cursor, clickedCursor);
}

void AboutState::tick()
{
	backButton.tick();
}

EState AboutState::next()
{
	if (backButton.isClicked) {
		backButton.isClicked = false;
		return backButton.next();
	}
	return ABOUT;
}
