#include "NumButton.h"
#include "sfwdraw.h"
using namespace sfw;


NumButton::NumButton()
{
	clickTimer = 0.f;
}

NumButton::NumButton(unsigned a_font, float a_x1, float a_y1, float width, float height, unsigned a_color, float inInc, float inEdit, bool inPos)
{
	font = a_font;
	x1 = a_x1;
	x2 = x1 + width;
	y1 = a_y1;
	y2 = y1 - height;
	color = a_color;

	incrementNum = inInc;
	editNum = inEdit;
	isPos = inPos;

	clickTimer = 0.f;
	isPos ? text = "\36" : text = "\37";
}

NumButton::~NumButton()
{
}

void NumButton::onClicked()
{
	isClicked = true;
	editNum = 0;
	
	if (clickTimer <= 0) 
		isPos ? editNum += incrementNum : editNum -= incrementNum;

	clickTimer = .1f;
}

void NumButton::tick(float deltaTime)
{
	if (getMouseX() > x1 && getMouseX() < x2 && getMouseY() < y1 && getMouseY() > y2 && getMouseButton(0))
	{
		onClicked();
	}

	if (clickTimer > 0)
		clickTimer -= deltaTime;
}

float NumButton::getNum()
{
	return editNum;
}

void NumButton::setNum(float inNum)
{
	editNum = inNum;
}
