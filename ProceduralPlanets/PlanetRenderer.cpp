#include "pch.h"
#include "PlanetRenderer.h"

PlanetRenderer::PlanetRenderer()
{
	planetShader.Add("Shaders/planet.vert", GL_VERTEX_SHADER);
	planetShader.Add("Shaders/planet.frag", GL_FRAGMENT_SHADER);
	planetShader.Link();
}

PlanetRenderer::~PlanetRenderer()
{
	planets.clear();
}

void PlanetRenderer::AddPlanet(Planet * planet)
{
	planets.push_back(planet);
}

void PlanetRenderer::Draw(Camera* camera)
{
	planetShader.Use();

	//camera
	planetShader.SetMatrix4("view", camera->getViewMatrix());
	planetShader.SetMatrix4("projection", camera->Projection);
	planetShader.SetVector3f("viewPos", vec3(camera->Position.x, camera->Position.y, camera->Position.z));

	//light
	planetShader.SetVector3f("dirLight.direction", light.direction.x, light.direction.y, light.direction.z);
	planetShader.SetVector3f("dirLight.ambient", light.ambient.x, light.ambient.y, light.ambient.z);
	planetShader.SetVector3f("dirLight.diffuse", light.diffuse.x, light.diffuse.y, light.diffuse.z);
	planetShader.SetInteger("dirLight.apply", light.apply);

	for (auto i = planets.begin(); i != planets.end(); i++) {
		(*i)->Draw();
	}
}
