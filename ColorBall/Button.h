#pragma once
#include <string>

//Anywhere there is a button there will also be a cursor.
//So, it seems safe to put the cursor function in the button header.
void cursorDraw();
void cursorDraw(int normalTex, int clickedTex);

class Button
{
protected:
	int font;
	int size;
	//x1 and y1 define the UPPER-RIGHT corner of the button
	float x1, x2, y1, y2;
	unsigned color;
	std::string text;
public:
	Button();
	Button(int a_font, float a_x1, float a_y1, float width, float height, int a_color, std::string a_text);
	//Optional initializer, using font size
	Button(int a_font, float a_x1, float a_y1, float width, float height, int a_size, int a_color, std::string a_text);
	~Button();

	bool isClicked;
	virtual void draw();
	virtual void tick();

	//The function to call when the button is clicked
	virtual void onClicked() = 0;

	//Getters, no setters
	unsigned getFont();

	float getX1();
	float getX2();
	float getY1();
	float getY2();

	unsigned getColor();
	std::string getText();
};

