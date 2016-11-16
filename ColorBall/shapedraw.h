#pragma once
#include "Shapes.h"

namespace spd
{
	void drawCircle(const Circle &t, unsigned color);
	
	void drawAABB(const AABB &box, unsigned color);

	void drawPlane(const Plane &p, unsigned color);

	void drawHull(const Hull &h, unsigned color);
}