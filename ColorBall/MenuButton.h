#pragma once
#include "Button.h"
#include "StateEnum.h"

class MenuButton :
	public Button
{

	EState nextState;
public:
	MenuButton();
	MenuButton(int a_font, float a_x1, float a_y1, float width, float height, int a_color, std::string a_text, EState a_nextState);
	~MenuButton();

	//Implementation of pure virtual function
	void onClicked();

	EState next() const;
};

