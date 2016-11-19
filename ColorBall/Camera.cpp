#include "Camera.h"
#include "GameState.h"


Camera::Camera(int W, int H)
{
	proj = translate(W, H) * scale(4, 4);
}


Camera::~Camera()
{
}

mat3 Camera::getCameraMatrix() const
{
	return proj * inverse(transform.getGlobalTransform());
}

void Camera::update(float deltaTime, const vec2 &movement, GameState & gs)
{
	transform.pos = movement;
}
