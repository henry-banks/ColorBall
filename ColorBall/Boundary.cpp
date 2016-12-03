#include "Boundary.h"
#include "sfwdraw.h"
#include "shapedraw.h"
using namespace spd;


Boundary::Boundary()
{
	vec2 hullVerts[] = { {0,0}, {1,1} };
	collider = Collider(hullVerts, 2);

	isPos = false;
}

Boundary::Boundary(int x1, int y1, int x2, int y2, bool isVert_a)
{
	vec2 hullVerts[] ={ {x1,y1}, {x2,y2} };
	collider = Collider(hullVerts, 2);

	isPos = isVert_a;
}

Boundary::Boundary(vec2 v1, vec2 v2, bool isVert_a)
{
	vec2 hullVerts[] = { v1,v2 };
	collider = Collider(hullVerts, 2);

	isPos = isVert_a;
}

Boundary::Boundary(vec2 hullVerts[], bool isVert_a)
{
	collider = Collider(hullVerts, 2);

	isPos = isVert_a;
}


Boundary::~Boundary()
{
}

void Boundary::debugDraw(const mat3 & t)
{
	collider.StaticDraw(t, CYAN);
}
