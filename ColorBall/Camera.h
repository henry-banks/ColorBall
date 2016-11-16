#pragma once
#include "Transform.h"
class Camera
{
public:
	Camera();
	~Camera();

	Transform	transform;
	mat3		proj;	//Projection

	mat3 getCameraMatrix() const; //returns proj
	void update(float deltaTime, class GameState &gs);
};

