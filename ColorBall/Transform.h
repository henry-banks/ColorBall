#pragma once
#include "vec2.h"
#include "mat3.h"
class Transform
{
public:
	Transform();
	Transform(float x, float y);

	Transform(float x, float y, float w, float h, float s);
	//Transform(float x = 0, float y = 0, float w = 0, float h = 0, float s = 0);
	~Transform();

	vec2 pos;
	vec2 scl;
	//AKA 'facing'
	float rotAngle;

	Transform *m_parent;

	vec2 getUp() const;
	vec2 getDir() const;
	void setDir(const vec2 &inDir);

	vec2 getGlobalPos()		const;
	vec2 getGlobalRight()	const;
	vec2 getGlobalUp()		const;
	float getGlobalAngle()	const;

	mat3 getLocalTransform() const;
	mat3 getGlobalTransform() const;
 
	void debugDraw(const mat3 &t = mat3Identity()) const;
};