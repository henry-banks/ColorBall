#include "State.h"



State::State()
{
}

State::State(unsigned inFont)
{
	font = inFont;
}


State::~State()
{
}

EState State::next()
{
	return nextState;
}
