#pragma once

#include "mat3.h"

//Bounding Volumes
struct Circle
{
	vec2 pos;	//offset
	float rad;
};
Circle	operator*(const mat3 &t, const Circle &c);
bool	operator==(const Circle &a, const Circle &b);


//Axis-Aligned Bounding Box
struct AABB
{
	vec2 pos;
	vec2 he; //Half-extents - x = half-width, y = half-height
	
	vec2 min() const;
	vec2 max() const;
};
AABB	operator*(const mat3 &t, const AABB &b);
//Must input an array of four points
AABB fromBoxAABB(const vec2 p[]);

struct Plane
{
	vec2 pos, dir;
};
Plane	operator*(const mat3 &t, const Plane &p);
bool	operator==(const Plane &a, const Plane &b);

struct Ray
{

};
Ray		operator*(const mat3 &t, const Ray &r);

//Convex Hull
struct Hull
{
	//Arbitrary limit of 16 because we probably won't go above it for this example
	vec2 vertices[16];
	vec2 normals[16];
	size_t size;

	//Assume clockwise
	/*Loop through every neighboring pair of vertices
	*Evaluate the normal of that pair and store it*/
	
	Hull(const vec2 inVertices[], unsigned inSize);

	Hull();
};
//Multiply each vertex by the matrix
Hull	operator*(const mat3 &t, const Hull &h);

//If convex hulls are same size, loop through and compare vertices and normals
bool	operator==(const Hull &a, const Hull &b);