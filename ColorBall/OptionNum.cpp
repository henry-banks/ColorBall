#include "OptionNum.h"
#include "sfwdraw.h"
#include <string>
using namespace sfw;
using namespace std;

OptionNum::OptionNum()
{
}

OptionNum::OptionNum(unsigned a_font, string inText, float a_x1, float a_y1, float a_height, unsigned a_color, float inInc, float inEdit)
{
	font = a_font;
	color = a_color;
	num = inEdit;
	x1 = a_x1;
	y1 = a_y1;
	height = a_height;
	text = inText;

	incButton = NumButton(font, a_x1, a_y1, (height / 2), (height / 2), color, inInc, num, true);
	decButton = NumButton(font, a_x1, a_y1 - (height / 2), (height / 2), (height / 2), color, inInc, num, false);
}


OptionNum::~OptionNum()
{
}

void OptionNum::draw()
{
	incButton.draw();
	decButton.draw();


	int num_print = round(num);
	string numString = to_string(num_print);
	drawString(font, numString.c_str(), x1 + (height / 2) + 10, y1 - (height / 4), height/2, height/2, 0, '\0', color);

	drawString(font, "-", 75, y1 - (height / 3), height / 3, height / 3, 0, '\0', color);
	drawString(font, text.c_str(), 75 + height/2, y1 - (height / 3), height / 3, height / 3, 0, '\0', color);
}

void OptionNum::tick(float deltaTime)
{
	incButton.tick(deltaTime);
	decButton.tick(deltaTime);

	if (incButton.isClicked)
	{
		incButton.isClicked = false;
		num += incButton.getNum();
	}
	if (decButton.isClicked)
	{
		decButton.isClicked = false;
		num += decButton.getNum();
	}
}

float OptionNum::getNum()
{
	return num;
}
