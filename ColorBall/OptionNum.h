#pragma once
#include "NumButton.h"
#include <string>
using namespace std;

class OptionNum
{
	NumButton incButton;
	NumButton decButton;

	float num;
	unsigned font;
	unsigned color;
	string text;

	float x1, y1, height;
public:
	OptionNum();
	OptionNum(unsigned a_font, string inText, float a_x1, float a_y1, float a_height, unsigned a_color, float inInc, float inEdit);
	~OptionNum();

	void draw();
	void tick(float deltaTime);

	float getNum();
};

