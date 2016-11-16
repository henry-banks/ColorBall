#include "Test.h"
#include <math.h>
#include <iostream>

int doNothing(int x)
{
	return x;
}



float Quadratic_y(float x)
{
	return (x*x) + (2*x) - 7;
}

QuadResult QuadFormula(float a, float b, float c)
{	
	float determinant = sqrt((b*b) - 4 * (a*c));

	QuadResult out;
	out.leftRoot = (b - determinant) / (2 * a);
	out.rightRoot = (b + determinant) / (2 * a);
	out.roots = 0;

	if (determinant > 0) {
		out.roots = 2;
	}
	else if (determinant == 0){
		out.roots = 1;
	}

	return out;
}

float LinBlend(float a, float b, float c)
{
	return a + (c*(b - a));
}

float Distance(Point2D p1, Point2D p2)
{
	return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

float InnerProd(Point3D p, Point3D q)
{
	return (p.x * q.x) + (p.y * q.y) + (p.z * q.z);
}

float DistFromPlane(TestPlane p, Point3D x)
{
	//This is for debugging
	float top = ((p.a*x.x) + (p.b*x.y) + (p.c*x.z) + p.d);
	float bot = sqrt(pow(p.a, 2) + pow(p.b, 2) + pow(p.c, 2));
	float out = top / bot;
	return out;
}

Point3D CubicBezier(float t, Point3D p0, Point3D p1, Point3D p2, Point3D p3)
{
	float ot = 1 - t;
	Point3D out;

	out.x = pow(ot, 3)*p0.x + 3 * pow(ot, 2)*(t*p1.x) + 3 * ot*((t*t)*p2.x) + (pow(t, 3)*p3.x);
	out.y = pow(ot, 3)*p0.y + 3 * pow(ot, 2)*(t*p1.y) + 3 * ot*((t*t)*p2.y) + (pow(t, 3)*p3.y);
	out.z = pow(ot, 3)*p0.z + 3 * pow(ot, 2)*(t*p1.z) + 3 * ot*((t*t)*p2.z) + (pow(t, 3)*p3.z);
	return out;
}

TestPlane initp(float inA, float inB, float inC, float inD)
{
	TestPlane out;
	out.a = inA;
	out.b = inB;
	out.c = inC;
	out.d = inD;

	return out;
}

Point3D init3(float inX, float inY, float inZ)
{
	Point3D out;
	out.x = inX;
	out.y = inY;
	out.z = inZ;

	return out;
}

Point2D init2(float inX, float inY)
{
	Point2D out;
	out.x = inX;
	out.y = inY;

	return out;
}
