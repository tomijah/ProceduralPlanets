#include "pch.h"
#include "includes.h"
#include "Display.h"
#include "Planet.h"
#include "PlanetRenderer.h"
#include "Camera.h"

using namespace std;
using namespace glm;

int main()
{
	Display display("Procedural planets", WIDTH, HEIGHT);
	Camera camera(vec3(0.0f, 0.0f, 200.0f));
	Planet earth(65, "Earth", vec3(0.0f, 0.0f, 0.0f));
	PlanetRenderer renderer;
	renderer.AddPlanet(&earth);

	camera.Look(earth.GetPosition());

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	while (!display.ShouldClose())
	{




		glClearDepth(1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		renderer.Draw(&camera);

		display.SwapBuffers();
		display.PollEvents();
	}
	return 0;
}