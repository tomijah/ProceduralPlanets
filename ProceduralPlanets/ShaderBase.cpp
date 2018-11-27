#include "pch.h"
#include "ShaderBase.h"


ShaderBase::ShaderBase()
{
	Program = glCreateProgram();
}

ShaderBase::~ShaderBase()
{
	glDeleteProgram(Program);
}

void ShaderBase::Use()
{
	glUseProgram(Program);
}

void ShaderBase::UnUse()
{
	glUseProgram(0);
}

void ShaderBase::AttachShader(const std::string & code, GLenum shaderType)
{
	GLuint id = glCreateShader(shaderType);
	const GLchar* source[1];
	source[0] = code.c_str();

	glShaderSource(id, 1, source, nullptr);

	glCompileShader(id);
	GLint success = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);
		glDeleteShader(id);
		std::cerr << &(errorLog[0]) << std::endl;
	}

	shaders.push_back(id);
	glAttachShader(Program, id);
}

void ShaderBase::Link()
{
	glLinkProgram(Program);
	GLint isLinked = 0;
	glGetProgramiv(Program, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(Program, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<char> errorLog(maxLength);
		glGetProgramInfoLog(Program, maxLength, &maxLength, &errorLog[0]);
		glDeleteProgram(Program);
		std::cerr << &(errorLog[0]) << std::endl;
	}

	for (auto const& s : shaders) {
		glDetachShader(Program, s);
		glDeleteShader(s);
	}
}

void ShaderBase::SetFloat(const GLchar *name, GLfloat value, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniform1f(glGetUniformLocation(this->Program, name), value);
}
void ShaderBase::SetInteger(const GLchar *name, GLint value, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniform1i(glGetUniformLocation(this->Program, name), value);
}
void ShaderBase::SetVector2f(const GLchar *name, GLfloat x, GLfloat y, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniform2f(glGetUniformLocation(this->Program, name), x, y);
}
void ShaderBase::SetVector2f(const GLchar *name, const glm::vec2 &value, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniform2f(glGetUniformLocation(this->Program, name), value.x, value.y);
}
void ShaderBase::SetVector3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniform3f(glGetUniformLocation(this->Program, name), x, y, z);
}
void ShaderBase::SetVector3f(const GLchar *name, const glm::vec3 &value, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniform3f(glGetUniformLocation(this->Program, name), value.x, value.y, value.z);
}
void ShaderBase::SetVector4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniform4f(glGetUniformLocation(this->Program, name), x, y, z, w);
}
void ShaderBase::SetVector4f(const GLchar *name, const glm::vec4 &value, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniform4f(glGetUniformLocation(this->Program, name), value.x, value.y, value.z, value.w);
}
void ShaderBase::SetMatrix4(const GLchar *name, const glm::mat4 &matrix, GLboolean useShader)
{
	if (useShader)
		this->Use();
	glUniformMatrix4fv(glGetUniformLocation(this->Program, name), 1, GL_FALSE, glm::value_ptr(matrix));
}