#include "Boundary.h"
#include "shapedraw.h"
using namespace spd;


Boundary::Boundary()
{
	vec2 hullVerts[] = { {0,0}, {1,1} };
	collider = Collider(hullVerts, 2);

	//transform.pos = vec2{ 0,0 };

	//get midpoint of Collider-line
	vec2 tPos = { (collider.hull.vertices[0].x + collider.hull.vertices[1].x) / 2,
				  (collider.hull.vertices[0].y + collider.hull.vertices[1].y) / 2 };
	transform.pos = tPos;

	isVert = false;
}

Boundary::Boundary(int x1, int y1, int x2, int y2, bool isVert_a)
{
	vec2 hullVerts[] ={ {x1,y1}, {x2,y2} };
	collider = Collider(hullVerts, 2);

	//transform.pos = vec2{ (float)x1,(float)y1 };

	vec2 tPos = { (collider.hull.vertices[0].x + collider.hull.vertices[1].x) / 2.f,
				  (collider.hull.vertices[0].y + collider.hull.vertices[1].y) / 2.f };
	transform.pos = tPos;

	isVert = isVert_a;
}

Boundary::Boundary(vec2 v1, vec2 v2, bool isVert_a)
{
	vec2 hullVerts[] = { v1,v2 };
	collider = Collider(hullVerts, 2);

	//transform.pos = v1;

	vec2 tPos = { (collider.hull.vertices[0].x + collider.hull.vertices[1].x) / 2,
				  (collider.hull.vertices[0].y + collider.hull.vertices[1].y) / 2 };
	transform.pos = tPos;

	isVert = isVert_a;
}

Boundary::Boundary(vec2 hullVerts[], bool isVert_a)
{
	collider = Collider(hullVerts, 2);

	transform.pos = hullVerts[0];

	/*vec2 tPos = { (collider.hull.vertices[0].x + collider.hull.vertices[1].x) / 2,
				  (collider.hull.vertices[0].y + collider.hull.vertices[1].y) / 2 };
	transform.pos = tPos;*/

	isVert = isVert_a;
}


Boundary::~Boundary()
{
}

void Boundary::debugDraw(const mat3 & t)
{
	collider.DebugDraw(t, transform);
}
