#pragma once
#include "vec3.h"

/*REMINDER: These are COLUMN-BASED
That means that mat3.mm[0][1] will be in the SECOND ROW of the FIRST COLUMN, not the SECOND COLUMN of the FIRST ROW
eg. mat3.mm[0][1] = 2 will do this:
|0 0 0|
|2 0 0|
|0 0 0|*/

union mat3
{
	float m[9];		//1d array
	float mm[3][3];	//2d array
	vec3 c[3];		//column vectors

	float  operator[](unsigned idx) const;
	float &operator[](unsigned idx);
};

mat3 mat3Identity();

mat3 operator+(const mat3 &l, const mat3 &r);
mat3 operator+(const mat3 &l, float r);
vec3 operator+(const mat3 &l, const vec3 &r);
mat3 operator-(const mat3 &l, const mat3 &r);
mat3 operator- (const mat3 &l);

mat3 transpose(const mat3 &l);

bool operator==(const mat3 &l, const mat3 &r);

mat3 operator*(const mat3 &l, const float &r);
mat3 operator*(const float &l, const mat3 &r);
mat3 operator*(const mat3 &l, const mat3 &r);
vec3 operator*(const mat3 &l, const vec3 &r);

mat3 inverse(const mat3 &l);
float determinant(const mat3 &l);

mat3 scale(const vec2 &s);
mat3 scale(float x,float y);

mat3 translate(const vec2 &t);
mat3 translate(float x,float y);

mat3 rotationDegrees(float a);
mat3 rotationRadians(float a);

void debugDraw(const mat3 &in);