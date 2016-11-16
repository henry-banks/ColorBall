#include "mat3.h"
#include "flops.h"
#include <iostream>
#include <math.h>

mat3 mat3Identity()
{
	return mat3{1,0,0,0,1,0,0,0,1};
}

mat3 operator+(const mat3 & l, const mat3 & r)
{
	mat3 out;
	for (int i = 0; i < 9; i++)
	{
		out.m[i] = l.m[i] + r.m[i];
	}

	return out;
}

mat3 operator+(const mat3 & l, float r)
{
	mat3 out;
	for (int i = 0; i < 9; i++)
	{
		out.m[i] = l.m[i] + r;
	}

	return out;
}

vec3 operator+(const mat3 & l, const vec3 & r)
{
	vec3 out;
	for (int i = 0; i < 3; i++)
	{
		out[i] = l.m[i] + r[i];
	}

	return out;
}

mat3 operator-(const mat3 & l, const mat3 & r)
{
	mat3 out;
	for (int i = 0; i < 9; i++)
	{
		out.m[i] = l.m[i] - r.m[i];
	}

	return out;
}

mat3 operator-(const mat3 & l)
{
	mat3 out;
	for (int i = 0; i < 9; i++)
	{
		out.m[i] = -l.m[i];
	}

	return out;
}

mat3 transpose(const mat3 & l)
{
	mat3 out;
	out = l;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			out.mm[i][j] = l.mm[j][i];
		}
	}
	return out;
}

bool operator==(const mat3 & l, const mat3 & r)
{
	bool out = true;
	for (int i = 0; i < 9; i++)
	{
		if (l.m[i] != r.m[i]) {
			out = false;
			break;
		}
	}

	return out;
}

mat3 operator*(const mat3 & l, const float & r)
{
	mat3 out = l;
	for (int col = 0; col < 3; col++) {
		for (int row = 0; row < 3; row++) {
			out.mm[col][row] *= r;
		}
	}
	return out;
}

mat3 operator*(const float & l, const mat3 & r)
{
	mat3 out = r;
	for (int col = 0; col < 3; col++) {
		for (int row = 0; row < 3; row++) {
			out.mm[col][row] *= l;
		}
	}
	return out;
}

mat3 operator*(const mat3 & l, const mat3 & r)
{
	// This is all magic math that esme uses.
	mat3 c = transpose(l);
	mat3 out;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			out.mm[i][j] = dotProd(c.c[j], r.c[i]);
		}
	}
	return out;
}

vec3 operator*(const mat3 & l, const vec3 & r)
{
	vec3 out;
	mat3 c = transpose(l);

	for (int i = 0; i < 3; i++)
	{
		out.v[i] = dotProd(c.c[i], r);
	}
	return out;
}

mat3 inverse(const mat3 & l)
{
	mat3 out;
	//more magic math.  it's all magic and all math
	//This particular magic math is called the Triple Cross Product
	out.c[0] = crossProd(l.c[1], l.c[2]);
	out.c[1] = crossProd(l.c[2], l.c[0]);
	out.c[2] = crossProd(l.c[0], l.c[1]);

	return 1/determinant(l)*transpose(out);
}

float determinant(const mat3 & l)
{
	//THIS IS ALL MAGIC MATH
	/*float det = (l.mm[0][0] * ((l.mm[1][1] * l.mm[2][2]) - (l.mm[1][2] * l.mm[2][1]))) -
				(l.mm[0][1] * ((l.mm[1][0] * l.mm[2][2]) - (l.mm[1][2] * l.mm[2][0]))) +
				(l.mm[0][2] * ((l.mm[1][0] * l.mm[2][1]) - (l.mm[1][1] * l.mm[2][0])));*/

	return dotProd(l.c[0], crossProd(l.c[1], l.c[2]));
}

mat3 scale(const vec2 & s)
{
	mat3 out = mat3Identity();
	out.mm[0][0] = s.x;
	out.mm[1][1] = s.y;
	return out;
}

mat3 scale(float x, float y)
{
	mat3 out = mat3Identity();
	out.mm[0][0] = x;
	out.mm[1][1] = y;
	return out;
}


mat3 translate(const vec2 & t)
{
	mat3 out = mat3Identity();
	out.mm[2][0] = t.x;
	out.mm[2][1] = t.y;
	return out;
}

mat3 translate(float x, float y)
{
	mat3 out = mat3Identity();
	out.mm[2][0] = x;
	out.mm[2][1] = y;
	return out;
}

// -0.0000007 == 0
mat3 rotationDegrees(float a)
{
	mat3 out = mat3Identity();
	if (a == 90 || a == -90) {
		out = 
		{ 0, sinf(deg2rad(a)),  0,
			-sinf(deg2rad(a)),  0,  0,
			0,					0,				   1 };
	}
	else {
		out = { cosf(deg2rad(a)),  sinf(deg2rad(a)),  0,
			   -sinf(deg2rad(a)),  cosf(deg2rad(a)),  0, 
			    0,				   0,		   	      1 };
	}


	// find a position along a circle from an angle
	// { cos(angle), sin(angle) }

	//Round stuff if it's essentially an integer(?)
	/*if (fequals(out.mm[0][0], roundf(out.mm[0][0])))
		out.mm[0][0] = roundf(out.mm[0][0]);

	if (fequals(out.mm[0][1], roundf(out.mm[0][1])))
		out.mm[0][1] = roundf(out.mm[0][1]);

	if (fequals(out.mm[1][0], roundf(out.mm[1][0])))
		out.mm[1][0] = roundf(out.mm[1][0]);

	if (fequals(out.mm[1][1], roundf(out.mm[1][1])))
		out.mm[1][1] = roundf(out.mm[1][1]);*/

	return out;
}

//This is probably broken
mat3 rotationRadians(float a)
{
	mat3 out = { cosf(a), sinf(a), 0,
				 -sinf(a),  cosf(a), 0,
				 0,		   0,	    1 };

	/*vec2 d = fromAngle(a);
	mat3 out = mat3Identity();
	out.c[0].xy = d;
	out.c[1].xy = -perp(d);*/

	//Round stuff if it's essentially an integer(?)
	/*if (fequals(out.mm[0][0], roundf(out.mm[0][0])))
		out.mm[0][0] = roundf(out.mm[0][0]);

	if (fequals(out.mm[0][1], roundf(out.mm[0][1])))
		out.mm[0][1] = roundf(out.mm[0][1]);

	if (fequals(out.mm[1][0], roundf(out.mm[1][0])))
		out.mm[1][0] = roundf(out.mm[1][0]);

	if (fequals(out.mm[1][1], roundf(out.mm[1][1])))
		out.mm[1][1] = roundf(out.mm[1][1]);*/

	return out;
}


void debugDraw(const mat3 &in)
{
	printf("Position: x: %f, y: %f\n\n", in.mm[2][0], in.mm[2][1]);

	printf("Full matrix:");
	printf("\n%f %f %f", in.mm[0][0], in.mm[1][0], in.mm[2][0]);
	printf("\n%f %f %f", in.mm[0][1], in.mm[1][1], in.mm[2][1]);
	printf("\n%f %f %f", in.mm[0][2], in.mm[1][2], in.mm[2][2]);
}

float mat3::operator[](unsigned idx) const
{
	return m[idx];
}

float & mat3::operator[](unsigned idx)
{
	return m[idx];
}
