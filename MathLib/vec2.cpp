#include "vec2.h"
#include "flops.h"
#include <math.h>

vec2 vInit2(float inX, float inY)
{
	vec2 out;
	out.x = inX;
	out.y = inY;

	return out;
}

vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	vec2 out;
	out.x = lhs.x + rhs.x;
	out.y = lhs.y + rhs.y;

	return out;
}

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	vec2 out;
	out.x = lhs.x - rhs.x;
	out.y = lhs.y - rhs.y;

	return out;
}

vec2 operator-(const vec2 & v)
{
	vec2 out;
	out.x = -v.x;
	out.y = -v.y;
	return out;
}

vec2 operator*(const vec2 & lhs, float rhs)
{
	vec2 out;
	out.x = lhs.x * rhs;
	out.y = lhs.y * rhs;

	return out;
}

vec2 operator*(float lhs, const vec2 & rhs)
{
	vec2 out;
	out.x = lhs * rhs.x;
	out.y = lhs * rhs.y;

	return out;
}

vec2 operator*(const vec2 & lhs, const vec2 & rhs)
{
	vec2 out;
	out.x = lhs.x * rhs.x;
	out.y = lhs.y * rhs.y;

	return out;
}

vec2 operator/(const vec2 & lhs, const vec2 & rhs)
{
	vec2 out;
	out.x = lhs.x / rhs.x;
	out.y = lhs.y / rhs.y;

	return out;
}

vec2 operator/(const vec2 & lhs, float rhs)
{
	vec2 out;
	out.x = lhs.x / rhs;
	out.y = lhs.y / rhs;
	return out;
}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs + rhs;
}

vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs - rhs;
}

vec2 & operator*=(vec2 & lhs, float rhs)
{
	return lhs = lhs * rhs;
}

vec2 & operator*=(float lhs, vec2 & rhs)
{
	return  rhs = rhs * lhs;
}

vec2 & operator/=(vec2 & lhs, vec2 & rhs)
{
	return lhs = lhs / rhs;
}

bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	return fequals(lhs.x, rhs.x) && fequals(lhs.y, rhs.y);
}

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	return lhs.x != rhs.x && lhs.y != rhs.y;
}

float magnitude(const vec2 & v)
{
	//Find hypotenuse
	float h = sqrt(powf(v.x, 2) + powf(v.y, 2));
	return h;
}

vec2 normalize(const vec2 & v)
{
	vec2 out;
	//I can't use vec2 / operator since v is a constant
	out.x = v.x / magnitude(v);
	out.y = v.y / magnitude(v);

	return out;
}

float dotProd(const vec2 & rhs, const vec2 & lhs)
{
	float out = (rhs.x*lhs.x) + (rhs.y * lhs.y);
	return out;
}

float angleBetween(const vec2 & rhs, const vec2 & lhs)
{
	float out = acos(dotProd(normalize(rhs), normalize(lhs)));
	return out;
}

vec2 perp(const vec2 & v)
{
	vec2 out;
	out.x = v.y;
	out.y = -v.x;

	return out;
}

float angle(const vec2 & v)
{
	return atan2f(v.y, v.x);
}

vec2 fromAngle(float a)
{
	vec2 out;
	out.x = cos(a);
	out.y = sin(a);

	return out;
}

vec2 min(const vec2 & a, const vec2 & b)
{
	vec2 out;
	out.x = a.x < b.x ? a.x : b.x;
	out.y = a.y < b.y ? a.y : b.y;

	return out;
}

vec2 max(const vec2 & a, const vec2 & b)
{
	vec2 out;
	out.x = a.x > b.x ? a.x : b.x;
	out.y = a.y > b.y ? a.y : b.y;

	return out;
}

vec2 project(const vec2 &i, const vec2 &n)
{
	return dotProd(i, normalize(n)) * normalize(n);
}

vec2 reflect(const vec2 &i, const vec2 &n)
{
	return i - 2*project(i,n);
}

float vec2::operator[](unsigned idx) const
{
	return v[idx];
}

float & vec2::operator[](unsigned idx)
{
	return v[idx];
}
