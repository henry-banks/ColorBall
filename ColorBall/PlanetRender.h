#pragma once
#include "Transform.h"
class PlanetRender
{
public:
	PlanetRender();
	PlanetRender(unsigned aColor, int aSize);
	~PlanetRender();

	unsigned color;
	float size;

	void draw(const Transform &planetTrans, const mat3 &t);
};

