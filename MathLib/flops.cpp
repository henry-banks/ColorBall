#include "flops.h"
#include <math.h>
#include "vec2.h"
#include <vector>

const float PI = 3.141592;

bool fequals(float lhs, float rhs)
{
	//Used for debugging
	float diff = fabs(lhs - rhs);

	if (diff < .000001) {
		return true;
	}

	return false;
}

float deg2rad(float deg)
{
	float out = (deg * PI)/ 180;
	return out;
}

float rad2deg(float rad)
{
	float out = (rad * 180) / PI;
	return out;
}

float linearHalf(float x)
{
	float result = x*0.5f;
	return result;
}

float slowToFast(float x)
{
	float result = pow(x,2);
	return result;
}

float fastToSlow(float x)
{
	float result = sqrt(x);
	return result;
}

float upDown(float x)
{
	float result = 1 - abs(2*x - 1);
	return result;
}

float bounce(float x)
{
	float result = 1 - abs(cos(x * 10)*(1 - x));
	return result;
}

float parabolicBump(float x)
{
	float result = (1 - pow(2*x - 1, 2));
	return result;
}

float lerp(float start, float end, float alpha)
{
	return (1-alpha)*start + (alpha)*end;

	return alpha*(end - start) + start;
}

float QuadBezier(float a, float b, float c, float alpha)
{
	//Lerp form point a to point b
	float mid1 = lerp(a, b, alpha);
	//lerp from point b to point c
	float mid2 = lerp(b, c, alpha);

	return lerp(mid1, mid2, alpha);
}

float HermiteSpline(float point1, float point2, float tan1, float tan2, float alpha)
{
	float tsq = alpha*alpha;
	float tcub = tsq*alpha;

	//WHY DOES IT COUNT IN BINARY?

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	float point = h00 * point1 + h10 * tan1 + h01 * point2 + h11 * tan2;

	return point;
}

float CardinalSpline(float point1, float point2, float point3, float tight, float alpha)
{
	float tan1 = (point2 - point1) * tight;
	float tan2 = (point3 - point2) * tight;

	return HermiteSpline(point1, point3, tan1, tan2, alpha);
}

float CatRomSpline(float start, float mid, float end, float tight)
{
	float tan1 = (mid - start) * tight;
	float tan2 = (mid - end) * tight;

	float asq = 0.5 * 0.5;
	float acub = asq * 0.5;

	float h00 = 2 * acub - 3 * acub + 1;
	float h01 = -2 * acub + 3 * asq;
	float h10 = acub - 2 * asq + 0.5;
	float h11 = acub - asq;

	float point = h00 * start + h10 * tan1 + h01 * mid + h11 * tan2;
	return point;
}

vec2 lerp(vec2 a, vec2 b, float alpha)
{
	vec2 retval;
	retval.x = lerp(a.x, b.x, alpha);
	retval.y = lerp(a.y, b.y, alpha);
	return retval;
}

vec2 QuadBezier(vec2 a, vec2 b, vec2 c, float alpha)
{
	vec2 retval;
	retval.x = QuadBezier(a.x, b.x, c.x, alpha);
	retval.y = QuadBezier(a.y, b.y, c.y, alpha);
	return retval;
}

vec2 HermiteSpline(vec2 point1, vec2 point2, vec2 tan1, vec2 tan2, float alpha)
{
	float tsq = alpha*alpha;
	float tcub = tsq*alpha;

	//WHY DOES IT COUNT IN BINARY?

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	vec2 point;
	point.x = h00 * point1.x + h10 * tan1.x + h01 * point2.x + h11 * tan2.x;
	point.y = h00 * point1.y + h10 * tan1.y + h01 * point2.y + h11 * tan2.y;

	return point;
}

vec2 CardinalSpline(vec2 point1, vec2 point2, vec2 point3, float tight, float alpha)
{
	vec2 tan1 = (point2 - point1) * tight;
	vec2 tan2 = (point3 - point2) * tight;

	return HermiteSpline(point1, point2, tan1, tan2, alpha);
}

vec2 CatRomSpline(vec2 start, vec2 mid, vec2 end, float alpha)
{
	return CardinalSpline(start, mid, end, .5, alpha);
}
