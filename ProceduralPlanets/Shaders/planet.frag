#version 330 core

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 color;
uniform vec3 viewPos;

struct Material {
	float shininess;
	vec3 color;
	bool hasTexture;
	bool applyLights;
};

uniform Material material;
uniform sampler2D diffuseTexture;

struct DirLight {
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	bool apply;
};

uniform DirLight dirLight;

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
	vec3 diffColor = material.color;
	if (material.hasTexture) {
		diffColor = vec3(texture(diffuseTexture, TexCoords));
	}

	vec3 lightDir = normalize(-light.direction);
	// Diffuse shading
	float diff = max(dot(normal, lightDir), 0.0);
	// Specular shading

	vec3 specularInit = vec3(material.shininess);

	vec3 specular;
	vec3 reflectDir = reflect(-lightDir, normal); 
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	specular = spec * light.diffuse;
	specular *= specularInit;

	// Combine results
	vec3 ambient = light.ambient * diffColor;
	vec3 diffuse = light.diffuse * diff * diffColor;


	return (ambient + diffuse + specular);
}

void main()
{
	vec3 norm = normalize(Normal);
	vec3 viewDir = normalize(viewPos - FragPos);

	vec3 result = vec3(0, 0, 0);

	if(!material.applyLights)
	{
		color = vec4(material.color, 1.0);
	}
	else{
		if (dirLight.apply) {
			result += CalcDirLight(dirLight, norm, viewDir);
		}

		color = vec4(result, 1.0);
	}
}