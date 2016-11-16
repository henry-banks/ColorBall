#include "shapedraw.h"
#include "sfwdraw.h"

void spd::drawCircle(const Circle & t, unsigned color)
{
	sfw::drawCircle(t.pos.x, t.pos.y, t.rad, 12, color);
}

void spd::drawAABB(const AABB & box, unsigned color)
{
	vec2 m1 = box.min();
	vec2 m2 = box.max();
	sfw::drawLine(m1.x, m1.y, m2.x, m1.y, color);
	sfw::drawLine(m1.x, m1.y, m1.x, m2.y, color);
	sfw::drawLine(m2.x, m2.y, m1.x, m2.y, color);
	sfw::drawLine(m2.x, m2.y, m2.x, m1.y, color);
}

void spd::drawPlane(const Plane & p, unsigned color)
{
	sfw::drawLine(p.pos.x, p.pos.y, (p.pos.x + p.dir.x * 30), (p.pos.y + p.dir.y * 30) , color);

	vec2 left = perp(p.dir);
	vec2 right = -perp(p.dir);
	sfw::drawLine(p.pos.x, p.pos.y, (p.pos.x + right.x * 80), (p.pos.y + right.y * 80) , RED);
	sfw::drawLine(p.pos.x, p.pos.y, (p.pos.x + left.x * 80), (p.pos.y + left.y * 80) , RED);
}

void spd::drawHull(const Hull & h, unsigned color)
{
	for (int i = 0; i < h.size && i < 16; i++)
	{
		sfw::drawLine(h.vertices[i].x, h.vertices[i].y, h.vertices[(i + 1) % h.size].x, h.vertices[(i + 1) % h.size].y, color);
	}

}

