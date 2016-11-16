#include "mat2.h"
#include "flops.h"
#include <iostream>
#include "mat3.h"

mat2 mat2Identity()
{
	return mat2{ 1,0,0,1 };
}

mat2 operator+(const mat2 & l, const mat2 & r)
{
	mat2 out;
	out.m[0] = l.m[0] + r.m[0];
	out.m[1] = l.m[1] + r.m[1];
	out.m[2] = l.m[2] + r.m[2];
	out.m[3] = l.m[3] + r.m[3];

	return out;
}

mat2 operator-(const mat2 & l, const mat2 & r)
{
	mat2 out;
	out.m[0] = l.m[0] - r.m[0];
	out.m[1] = l.m[1] - r.m[1];
	out.m[2] = l.m[2] - r.m[2];
	out.m[3] = l.m[3] - r.m[3];

	return out;
}

mat2 operator-(const mat2 & l)
{
	mat2 out;
	out.m[0] = l.m[0] * -1;
	out.m[1] = l.m[1] * -1;
	out.m[2] = l.m[2] * -1;
	out.m[3] = l.m[3] * -1;

	return out;
}

mat2 transpose(const mat2 & l)
{
	mat2 out;
	out.mm[0][0] = l.mm[0][0];
	out.mm[0][1] = l.mm[1][0];
	out.mm[1][0] = l.mm[0][1];
	out.mm[1][1] = l.mm[1][1];

	return out;
}

bool operator==(const mat2 & l, const mat2 & r)
{
	return
		fequals(l.m[0], r.m[0]) &&
		fequals(l.m[1], r.m[1]) &&
		fequals(l.m[2], r.m[2]) &&
		fequals(l.m[3], r.m[3]);
}

mat2 operator*(const mat2 & l, const float & r)
{
	mat2 out;
	out.m[0] = l.m[0] * r;
	out.m[1] = l.m[1] * r;
	out.m[2] = l.m[2] * r;
	out.m[3] = l.m[3] * r;

	return out;
}

mat2 operator*(const float & l, const mat2 & r)
{
	mat2 out;
	out.m[0] = r.m[0] * l;
	out.m[1] = r.m[1] * l;
	out.m[2] = r.m[2] * l;
	out.m[3] = r.m[3] * l;

	return out;
}

mat2 operator*(const mat2 & l, const mat2 & r)
{
	//This is all magic math that esme uses.
	mat2 c = transpose(l);
	mat2 out;

	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			out.mm[col][row] = dotProd(c.c[row], r.c[col]);
		}
	}
	return out;
}

vec2 operator*(const mat2 & l, const vec2 & r)
{
	mat2 c = l;
	vec2 out;

	out.v[0] = dotProd(c.c[0], r);
	out.v[1] = dotProd(c.c[1], r);

	return out;
}

mat2 inverse(const mat2 & l)
{
	mat2 out;
	out.mm[0][0] =  l.mm[1][1];
	out.mm[0][1] = -l.mm[0][1];
	out.mm[1][0] = -l.mm[1][0];
	out.mm[1][1] =  l.mm[0][0];

	out = out* (1 / determinant(out));

	return out;
}

float determinant(const mat2 & l)
{
	return (l.mm[0][0] * l.mm[1][1]) - (l.mm[0][1] * l.mm[1][0]);
}

float mat2::operator[](unsigned idx) const
{
	return m[idx];
}

float & mat2::operator[](unsigned idx)
{
	return m[idx];
}