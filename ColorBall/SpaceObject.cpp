#include "SpaceObject.h"
#include <iostream>

void SpaceObject::init(vec2 transPos, vec2 transScl, float motorSpeed, unsigned aColor, int aSize, Transform* aParent, bool aIsOrigin)
{
	trans.pos = transPos;
	trans.scl = transScl;
	trans.m_parent = aParent;

	motor.rotSpeed = motorSpeed;

	render.color = aColor;
	render.size = aSize;

	isOrigin = aIsOrigin;
}

void SpaceObject::update(float deltaTime)
{
	motor.update(body);
	body.integrate(trans, deltaTime);
}

void SpaceObject::draw(const mat3 &t)
{
	render.draw(trans, t);
}

void SpaceObject::updateDraw(float deltaTime, const mat3 &t)
{

	update(deltaTime);
	draw(t);
}
