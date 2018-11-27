#include "pch.h"
#include "ShaderFromFile.h"
using namespace std;

ShaderFromFile::ShaderFromFile()
{
}


ShaderFromFile::~ShaderFromFile()
{
}

void ShaderFromFile::Add(const string& path, GLenum shaderType)
{
	ifstream file;
	file.open(path.c_str());

	string output;
	string line;
	if (file.is_open()) {
		while (file.good()) {
			getline(file, line);
			output.append(line + "\n");
		}

		AttachShader(output, shaderType);
		cout << "File: " << path << " loaded" << endl;
	}
	else {
		cout << "File: " << path << " error" << endl;
	}
}
