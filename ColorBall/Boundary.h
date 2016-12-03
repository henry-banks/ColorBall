#pragma once
#include "Collider.h"
class Boundary
{
public:
	Boundary();
	Boundary(int x1, int y1, int x2, int y2, bool isVert_a);
	Boundary(vec2 v1, vec2 v2, bool isVert_a);
	//NOTE: array must have only TWO vectors
	Boundary(vec2 hullVerts[], bool isVert_a);
	~Boundary();

	Collider collider;
	//True if collider borders either left or right side (a vertical boundary)
	bool isPos;

	void debugDraw(const mat3 &t);
};

