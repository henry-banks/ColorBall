#include "vec3.h"
#include "flops.h"
#include <math.h>

vec3 vInit3(float inX, float inY, float inZ)
{
	vec3 out;
	out.x = inX;
	out.y = inY;
	out.z = inZ;

	return out;
}

vec3 operator+(const vec3 & lhs, const vec3 & rhs)
{
	vec3 out;
	out.x = lhs.x + rhs.x;
	out.y = lhs.y + rhs.y;
	out.z = lhs.z + rhs.z;

	return out;
}

vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	vec3 out;
	out.x = lhs.x - rhs.x;
	out.y = lhs.y - rhs.y;
	out.z = lhs.z - rhs.z;

	return out;
}

vec3 operator-(const vec3 & v)
{
	vec3 out;
	out.x = -v.x;
	out.y = -v.y;
	out.z = -v.z;

	return out;
}

vec3 operator*(const vec3 & lhs, float rhs)
{
	vec3 out;
	out.x = lhs.x * rhs;
	out.y = lhs.y * rhs;
	out.z = lhs.z * rhs;

	return out;
}

vec3 operator*(float lhs, const vec3 & rhs)
{
	vec3 out;
	out.x = lhs * rhs.x;
	out.y = lhs * rhs.y;
	out.z = lhs * rhs.z;

	return out;
}

vec3 operator/(const vec3 & lhs, const vec3 & rhs)
{
	vec3 out;
	out.x = lhs.x / rhs.x;
	out.y = lhs.y / rhs.y;
	out.z = lhs.z / rhs.z;

	return out;
}

vec3 & operator+=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs + rhs;
}

vec3 & operator-=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs - rhs;
}

vec3 & operator*=(vec3 & lhs, float rhs)
{
	return lhs = lhs * rhs;
}

vec3 & operator*=(float lhs, vec3 & rhs)
{
	return rhs = rhs * lhs;
}

vec3 & operator/=(vec3 & lhs, vec3 & rhs)
{
	return lhs = lhs / rhs;
}

bool operator==(const vec3 & lhs, const vec3 & rhs)
{
	return fequals(lhs.x, rhs.x) && fequals(lhs.y, rhs.y) && fequals(lhs.z, rhs.z);
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	return lhs.x != rhs.x && lhs.y != rhs.y && lhs.z != rhs.z;
}

float magnitude(const vec3 & v)
{
	float h = sqrt((v.x*v.x) + (v.y*v.y) + (v.z*v.z));
	return h;
}

vec3 normalize(const vec3 & v)
{
	vec3 out;
	out.x = v.x / magnitude(v);
	out.y = v.y / magnitude(v);
	out.z = v.z / magnitude(v);

	return out;
}

float dotProd(const vec3 & rhs, const vec3 & lhs)
{
	return rhs.x*lhs.x + rhs.y * lhs.y + rhs.z * lhs.z;
}

float angleBetween(const vec3 & rhs, const vec3 & lhs)
{
	return acos(dotProd(normalize(rhs), normalize(lhs)));
}

vec3 crossProd(const vec3 & lhs, const vec3 & rhs)
{
	vec3 out;
	out.x = (lhs.y * rhs.z) - (lhs.z * rhs.y);
	out.y = (lhs.z * rhs.x) - (lhs.x * rhs.z);
	out.z = (lhs.x * rhs.y) - (lhs.y * rhs.x);

	return out;
}

float vec3::operator[](unsigned idx) const
{
	return v[idx];;
}

float & vec3::operator[](unsigned idx)
{
	return v[idx];
}
