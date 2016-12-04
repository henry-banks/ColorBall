#pragma once
#include "State.h"
#include "MenuButton.h"
class OptionState :
	public State
{
	int font;
	int cursor, clickedCursor;

	MenuButton confirmButton;
	MenuButton cancelButton;
	//Color buttons are the most basic buttons so I'm using one of those for the 'reset to deafult' button
	//ColorButton DefaultButton;

public:
	OptionState();
	~OptionState();
};

