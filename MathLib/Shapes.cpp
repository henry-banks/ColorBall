#include "Shapes.h"
#include "flops.h"
#include <math.h>

Circle operator*(const mat3 & t, const Circle & c)
{
	Circle out = c;

	//Set position
	out.pos = (t*vec3{ c.pos.x, c.pos.y, 1 }).xy;

	float xRad = magnitude(t * vec3{ 0,c.rad,0 });
	float yRad = magnitude(t * vec3{ c.rad,0,0 });
	
	out.rad = xRad > yRad ? xRad : yRad;

	return out;
}

bool operator==(const Circle & a, const Circle & b)
{
	return a.pos == b.pos && fequals(a.rad, b.rad);
}

AABB operator*(const mat3 & t, const AABB & b)
{
	AABB out = b;

	//do it not work?
	/*out.pos = (t * vec3{ b.pos.x, b.pos.y, 1 }).xy;
	out.he = (t * vec3{ b.he.x, b.he.y, 1 }).xy;*/

	vec3 tp[4];

	tp[0] = t * vec3{ b.min().x, b.min().y, 1 };
	tp[1] = t * vec3{ b.max().x, b.max().y, 1 };
	tp[2] = t * vec3{ b.min().x, b.max().y, 1 };
	tp[3] = t * vec3{ b.max().x, b.min().y, 1 };

	vec2 minv = tp[0].xy;
	vec2 maxv = tp[0].xy;

	for (int i = 0; i < 4; i++)
	{
		minv = min(minv, tp[i].xy);
		maxv = max(maxv, tp[i].xy);
	}
	out.pos = (minv + maxv) / 2;
	out.he = (maxv - minv) / 2;

	return out;
}

AABB fromBoxAABB(const vec2 p[])
{
	AABB out;

	//Setting up values to test against.
	vec2 minv{ INFINITY, INFINITY };
	vec2 maxv{ -INFINITY, -INFINITY};

	//Find min and max vertices
	for (int i = 0; i < 4; i++)
	{
		minv = min(minv, p[i]);
		maxv = max(maxv, p[i]);
	}

	//math-y math-ness
	out.pos = (minv + maxv) / 2;
	out.he = (maxv - minv) / 2;

	return out;
}

Plane operator*(const mat3 & t, const Plane & p)
{
	Plane out;
	out.pos = (t * vec3{ p.pos.x, p.pos.y, 1 }).xy;
	out.dir = normalize(t * vec3{ p.dir.x, p.dir.y, 0 }).xy;

	return out;
}

bool operator==(const Plane & a, const Plane & b)
{
	return (a.pos == b.pos) && (a.dir == b.dir);
}

Ray operator*(const mat3 & t, const Ray & r)
{
	return Ray();
}

Hull operator*(const mat3 & t, const Hull & h)
{
	Hull out;
	out.size = h.size;
	//Multiply vertices and normals by matrix
	for (int i = 0; i < out.size; i++)
	{
		out.vertices[i] = (t * vec3{h.vertices[i].x, h.vertices[i].y, 1 }).xy;
		out.normals[i] = normalize((t * vec3{ h.normals[i].x, h.normals[i].y, 0 }).xy);
	}

	return out;
}

bool operator==(const Hull & a, const Hull & b)
{
	//If the hulls are not the same size, they are not equal
	if (a.size != b.size)
		return false;

	//Compare vertices and normals
	for (int i = 0; i < a.size; i++)
	{
		if (a.vertices[i] != b.vertices[i] || a.normals[i] != b.normals[i])
			return false;
	}

	return true;
}

vec2 AABB::min() const
{
	vec2 out = pos - he;
	return out;
}

vec2 AABB::max() const
{
	vec2 out = pos + he;
	return out;
}

Hull::Hull(const vec2 inVertices[], unsigned inSize)
{
	size = inSize;
	for (int i = 0; i < inSize && i < 16; i++)
	{
		vertices[i] = inVertices[i];
		//i+1 % size will give us the first one when we get to the end
		normals[i] = -perp(normalize(inVertices[(i+1) % size] - inVertices[i]));
	}
}

Hull::Hull()
{
	size = 0;
}
