#pragma once
#include "Transform.h"

class ShipRender
{
public:
	ShipRender(unsigned inColor = 0xffffffff, float inSize = 1);
	~ShipRender();

	unsigned color;
	float size;

	void draw(const Transform &t, const mat3 &camera);

};