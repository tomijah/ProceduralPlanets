#pragma once
#include "Includes.h"

using namespace glm;

class Camera
{
public:
	Camera(vec3 position = vec3(0.0f, 5.0f, 2.0f), vec3 up = vec3(0.0f, 1.0f, 0.0f), float width = WIDTH, float height = HEIGHT);
	~Camera();
	glm::vec3 Position;
	glm::vec3 Up;
	glm::vec3 Target;
	bool recalculateMatrix = true;
	glm::mat4 getViewMatrix();
	glm::mat4 Projection;
	void Look(glm::vec3 target);
private:
	glm::mat4 viewMatrix;
};

