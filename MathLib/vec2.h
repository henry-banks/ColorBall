#pragma once

union vec2
{
	float v[2];
	struct {
		float x, y;
	};

	float  operator[](unsigned idx) const;
	float &operator[](unsigned idx);
};
vec2 vInit2(float inX, float inY);

vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &v);

vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator*(float lhs, const vec2 &rhs);
vec2 operator*(const vec2 &lhs, const vec2 &rhs);

vec2 operator/(const vec2 &lhs, const vec2 &rhs);
vec2 operator/(const vec2 &lhs, float rhs);

vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 &lhs, const vec2 &rhs);

vec2 &operator*=(vec2 &lhs, float rhs);
vec2 &operator*=(float lhs, vec2 &rhs);

vec2 &operator/=(vec2 &lhs, vec2 &rhs);

bool operator==(const vec2 &lhs, const vec2 &rhs);
bool operator!=(const vec2 &lhs, const vec2 &rhs);

float magnitude(const vec2 &v);

vec2 normalize(const vec2 &v);

float dotProd(const vec2 &rhs, const vec2 &lhs);
float angleBetween(const vec2 &rhs, const vec2 &lhs);

//2d only stuff
vec2 perp(const vec2 &v);
float angle(const vec2 &v);
vec2 fromAngle(float a);

vec2 min(const vec2 &a, const vec2 &b);
vec2 max(const vec2 &a, const vec2 &b);

//collision stuff
vec2 project(const vec2 &i, const vec2 &n);
vec2 reflect(const vec2 &i, const vec2 &n);