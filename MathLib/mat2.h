#pragma once
#include "vec2.h"

union mat2
{
	float m[4];		//1d array
	float mm[2][2];	//2d array
	vec2 c[2];		//column vectors

	float  operator[](unsigned idx) const;
	float &operator[](unsigned idx);
};

mat2 mat2Identity();

mat2 operator+(const mat2 &l, const mat2 &r);
mat2 operator-(const mat2 &l, const mat2 &r);
mat2 operator- (const mat2 &l);

mat2 transpose(const mat2 &l);

bool operator==(const mat2 &l, const mat2 &r);

mat2 operator*(const mat2 &l, const float &r);
mat2 operator*(const float &l, const mat2 &r);
mat2 operator*(const mat2 &l, const mat2 &r);
vec2 operator*(const mat2 &l, const vec2 &r);

mat2 inverse(const mat2 &l);
float determinant(const mat2 &l);