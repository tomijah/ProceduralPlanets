#include "pch.h"
#include "Camera.h"

Camera::Camera(vec3 position, vec3 up, float width, float height)
{
	this->Position = position;
	this->Up = up;
	this->Target = vec3(0.0f, 0.0f, 0.0f);
	this->Projection = perspective(45.0f, width / height, 0.1f, 10000.0f);
}

Camera::~Camera()
{
}

glm::mat4 Camera::getViewMatrix()
{
	if (recalculateMatrix) {
		viewMatrix = lookAt(Position, Position + Target, Up);
		recalculateMatrix = false;
	}

	return viewMatrix;
}

void Camera::Look(vec3 target)
{
	Target = normalize(target - Position);
	recalculateMatrix = true;
}
