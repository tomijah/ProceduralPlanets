#pragma once
#include "Includes.h"
#include "ShaderBase.h"

using namespace glm;

struct Vertex {
	vec3 position;
	vec3 normal;
	vec2 uv;
};

struct Material {
	vec3 color = vec3(1);
	GLfloat shininess = 0.0f;
	GLuint diffuseTextureId = 0;
	bool hasTexture = false;
	bool applyLights = true;
};


class Mesh
{
public:
	Mesh(vector<Vertex> vertices, std::vector<GLuint> indices, Material material);
	~Mesh();
	void Draw(ShaderBase *shader);
	void RemoveBuffers();
	void UpdateGeometry(std::vector<Vertex> vertices, std::vector<GLuint> indices);
	Material material;
private:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	GLuint VAO, VBO, EBO;
	void setupMesh();
};

