#pragma once
//Basic math library

int doNothing(int x);

//Day 1 exercises (Math Formula)

//The result of the quadratic formula
struct QuadResult
{
	float leftRoot, rightRoot;
	int roots;
};

struct Point2D
{
	float x, y;
};
Point2D init2(float inX, float inY);

struct Point3D
{
	float x, y, z;	
};
Point3D init3(float inX, float inY, float inZ);

struct TestPlane
{
	//a and b represent two opposite corners
	float a, b, c, d;
};
TestPlane initp(float inA, float inB, float inC, float inD);

//STATIC quadratic formula, returns y-coord of given x-coord
float Quadratic_y(float x);
//Returns roots and number of roots of given coefficients
QuadResult QuadFormula(float a, float b, float c);
//IT'S A LERP.
float LinBlend(float a, float b, float c);
//Returns distance between given points
float Distance(Point2D p1, Point2D p2);
//Returns inner product of given points
float InnerProd(Point3D p, Point3D q);
//Returns distance of point from given plane
float DistFromPlane(TestPlane p, Point3D x);
//Returns something that I assume has to do with bezier curves but I don't know what
Point3D CubicBezier(float t, Point3D p0, Point3D p1, Point3D p2, Point3D p3);