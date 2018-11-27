#pragma once
#include "Includes.h"

using namespace std;
using namespace glm;

class Planet
{
public:
	Planet(float radius, string name, vec3 position);
	~Planet();
	void Draw();
	vec3 GetPosition() {
		return position;
	}
private:
	float radius;
	string name;
	vec3 position;
};

