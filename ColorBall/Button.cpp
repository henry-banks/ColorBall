#include "Button.h"
#include "sfwdraw.h"

using namespace sfw;

Button::Button()
{
	isClicked = false;
	size = 20;
}

Button::Button(int a_font, float a_x1, float a_y1, float width, float height, int a_color, std::string a_text)
{
	isClicked = false;

	font = a_font;
	x1 = a_x1;
	x2 = x1 + width;
	y1 = a_y1;
	y2 = y1 - height;
	color = a_color;
	text = a_text;
	//Default to 20
	size = 20;
}


Button::Button(int a_font, float a_x1, float a_y1, float width, float height, int a_size, int a_color, std::string a_text)
{
	isClicked = false;

	font = a_font;
	x1 = a_x1;
	x2 = x1 + width;
	y1 = a_y1;
	y2 = y1 - height;
	color = a_color;
	text = a_text;

	size = a_size;
}

Button::~Button()
{
}

void Button::draw()
{
	//draw rectangle
	drawLine(x1, y1, x2, y1, color);
	drawLine(x1, y2, x2, y2, color);
	drawLine(x1, y1, x1, y2, color);
	drawLine(x2, y1, x2, y2, color);

	//All the math makes the text show up in the middle of the button
	drawString(font, text.c_str(), ((x1 + x2) / 2) - (text.size() * (size / 2)), ((y1 + y2) / 2) + size / 2, size, size, 0, '\0', color);
}

void Button::tick()
{
	if (getMouseX() > x1 && getMouseX() < x2 && getMouseY() < y1 && getMouseY() > y2 && getMouseButton(0))
	{
		onClicked();
	}
	//isClicked should only be true for a single tick
	/*if (isClicked) {
	isClicked = false;
	}*/
}

unsigned Button::getFont()
{
	return font;
}

float Button::getX1()
{
	return x1;
}

float Button::getX2()
{
	return x2;
}

float Button::getY1()
{
	return y1;
}

float Button::getY2()
{
	return y2;
}

unsigned Button::getColor()
{
	return color;
}

std::string Button::getText()
{
	return text;
}

void cursorDraw()
{
	if (sfw::getMouseButton(MOUSE_BUTTON_LEFT)) {
		//Geometry-based cursor
		drawCircle(getMouseX(), getMouseY(), 9, 15, 0x00ffff50);
		drawCircle(getMouseX(), getMouseY(), 8, 15, 0x00ffff80);
		drawCircle(getMouseX(), getMouseY(), 7, 15, 0x00ffffc0);
		drawCircle(getMouseX(), getMouseY(), 6, 15, 0x00fffff0);
		drawCircle(getMouseX(), getMouseY(), 5, 15, 0xFFFFFFc0);
		drawCircle(getMouseX(), getMouseY(), 4, 15, 0xFFFFFF80);
		drawCircle(getMouseX(), getMouseY(), 3, 15, 0xFFFFFF60);
		drawCircle(getMouseX(), getMouseY(), 2, 15, 0xFFFFFF40);
		drawCircle(getMouseX(), getMouseY(), 1, 15, 0xFFFFFF25);
	}
	else {
		//Geometry-based cursor
		drawCircle(getMouseX(), getMouseY(), 9, 15, 0x00ffff20);
		drawCircle(getMouseX(), getMouseY(), 8, 15, 0x00ffff50);
		drawCircle(getMouseX(), getMouseY(), 7, 15, 0x00ffff80);
		drawCircle(getMouseX(), getMouseY(), 6, 15, 0x00ffffc0);
		drawCircle(getMouseX(), getMouseY(), 5, 15, 0xFFFFFF80);
		drawCircle(getMouseX(), getMouseY(), 4, 15, 0xFFFFFF60);
		drawCircle(getMouseX(), getMouseY(), 3, 15, 0xFFFFFF40);
		drawCircle(getMouseX(), getMouseY(), 2, 15, 0xFFFFFF20);
		drawCircle(getMouseX(), getMouseY(), 1, 15, 0xFFFFFF05);
	}
}

void cursorDraw(int normalTex, int clickedTex)
{
	if (sfw::getMouseButton(MOUSE_BUTTON_LEFT)) {
		drawTexture(clickedTex, getMouseX(), getMouseY(), 20, 20);

		//Geometry-based cursor
		/*	drawCircle(getMouseX(), getMouseY(), 9, 15, 0x00ffff50);
		drawCircle(getMouseX(), getMouseY(), 8, 15, 0x00ffff80);
		drawCircle(getMouseX(), getMouseY(), 7, 15, 0x00ffffc0);
		drawCircle(getMouseX(), getMouseY(), 6, 15, 0x00fffff0);
		drawCircle(getMouseX(), getMouseY(), 5, 15, 0xFFFFFFc0);
		drawCircle(getMouseX(), getMouseY(), 4, 15, 0xFFFFFF80);
		drawCircle(getMouseX(), getMouseY(), 3, 15, 0xFFFFFF60);
		drawCircle(getMouseX(), getMouseY(), 2, 15, 0xFFFFFF40);
		drawCircle(getMouseX(), getMouseY(), 1, 15, 0xFFFFFF25);*/
	}
	else {
		drawTexture(normalTex, getMouseX(), getMouseY(), 20, 20);

		//Geometry-based cursor
		/*	drawCircle(getMouseX(), getMouseY(), 9, 15, 0x00ffff20);
		drawCircle(getMouseX(), getMouseY(), 8, 15, 0x00ffff50);
		drawCircle(getMouseX(), getMouseY(), 7, 15, 0x00ffff80);
		drawCircle(getMouseX(), getMouseY(), 6, 15, 0x00ffffc0);
		drawCircle(getMouseX(), getMouseY(), 5, 15, 0xFFFFFF80);
		drawCircle(getMouseX(), getMouseY(), 4, 15, 0xFFFFFF60);
		drawCircle(getMouseX(), getMouseY(), 3, 15, 0xFFFFFF40);
		drawCircle(getMouseX(), getMouseY(), 2, 15, 0xFFFFFF20);
		drawCircle(getMouseX(), getMouseY(), 1, 15, 0xFFFFFF05);*/
	}
}
