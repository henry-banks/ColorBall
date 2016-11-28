#pragma once
#include "StateEnum.h"

//Parent state class, abstract
class State
{
public:
	State();
	State(unsigned inFont);
	~State();

	unsigned font;
	EState nextState;

	//Activation
	virtual void play() = 0;
	//Update
	virtual void draw() = 0;
	virtual void tick() = 0;

	EState next();
};

