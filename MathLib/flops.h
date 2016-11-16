//FLoating point OPerationS
#pragma once
#include "vec2.h"

//Check if float numbers are equivalent to the 7th place (.0000001)
bool fequals(float lhs, float rhs);

float deg2rad(float deg);
float rad2deg(float rad);

float linearHalf(float x);

float slowToFast(float x);
float fastToSlow(float x);
float upDown(float x);
float bounce(float x);
float parabolicBump(float x);

float lerp(float start, float end, float alpha);

vec2 lerp(vec2 a, vec2 b, float alpha);
vec2 QuadBezier(vec2 a, vec2 b, vec2 c, float alpha);
//This is all math
vec2 HermiteSpline(vec2 point1, vec2 point2, vec2 tan1, vec2 tan2, float alpha);
vec2 CardinalSpline(vec2 point1, vec2 point2, vec2 point3, float tight, float alpha);
vec2 CatRomSpline(vec2 start, vec2 mid, vec2 end, float tight);

float lerp(float a, float b, float alpha);
float QuadBezier(float a, float b, float c, float alpha);
//This is all math
float HermiteSpline(float point1, float point2, float tan1, float tan2, float alpha);
float CardinalSpline(float point1, float point2, float point3, float tight, float alpha);
float CatRomSpline(float start, float mid, float end, float alpha);