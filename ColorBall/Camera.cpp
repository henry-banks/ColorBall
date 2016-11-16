#include "Camera.h"
#include "GameState.h"


Camera::Camera()
{
	proj = translate(600, 600) * scale(2, 2);
}


Camera::~Camera()
{
}

mat3 Camera::getCameraMatrix() const
{
	return proj * inverse(transform.getGlobalTransform());
}

void Camera::update(float deltaTime, GameState & gs)
{
	transform.pos = gs.player.transform.getGlobalPos();
}
