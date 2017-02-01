#pragma once
#include "Button.h"
class NumButton :
	public Button
{
	float incrementNum;
	float editNum;
	bool isPos;

	float clickTimer;

public:
	/*A button for either raising or lowering the value of a number
	*inInc: how much to increment by.  Do not make negative.
	*inEdit: the initial number that will be incremented.
	*inPos: set this to true if the button increases the given number,
			set to false if it decreases the given number (up/down)*/
	NumButton();
	NumButton(unsigned a_font, float a_x1, float a_y1, float width, float height, unsigned a_color, float inInc, float inEdit, bool inPos);
	~NumButton();

	void onClicked();
	void tick(float deltaTime);

	float getNum();
	void setNum(float inNum);
};

