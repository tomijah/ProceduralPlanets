#pragma once
#include "Includes.h"
#include "Planet.h"
#include "ShaderBase.h"
#include "ShaderFromFile.h"
#include "Camera.h"

using namespace glm;
using namespace std;

struct DirLight {
	vec3 direction = vec3(-1.0f, -1.0f, -1.0f);
	vec3 ambient = vec3(0);
	vec3 diffuse = vec3(1);
	bool apply;
};

class PlanetRenderer
{
public:
	PlanetRenderer();
	~PlanetRenderer();
	void AddPlanet(Planet* planet);
	void Draw(Camera* camera);
private:
	vector<Planet*> planets;
	ShaderFromFile planetShader;
	DirLight light;
};

