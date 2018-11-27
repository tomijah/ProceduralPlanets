#pragma once
#include "ShaderBase.h"
class ShaderFromFile :
	public ShaderBase
{
public:
	ShaderFromFile();
	~ShaderFromFile();
	void Add(const std::string& path, GLenum shaderType);
};


