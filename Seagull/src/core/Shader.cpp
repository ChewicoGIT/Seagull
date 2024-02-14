#include "Shader.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "GLAD/glad.h"

std::string OpenFile(const char* filePath) {

	std::ifstream shaderFile;
	shaderFile.open(filePath);

	if (!shaderFile.is_open()) {
		std::cout << filePath << " could not be open \n";
		return std::string();
	}

	std::stringstream returnContent;
	returnContent << shaderFile.rdbuf();

	shaderFile.close();
	return returnContent.str();	
}


unsigned int CreateShader(std::string source, unsigned int type) {

	unsigned int vertexShader;
	vertexShader = glCreateShader(type);

	const char* sourcePointer = source.c_str();
	glShaderSource(vertexShader, 1, &sourcePointer, NULL);
	glCompileShader(vertexShader);

	int  success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "Error in compiling shader : \n" << infoLog << "\n\nSource:\n" << source << "\n\n";
	}

	return vertexShader;
}

SG::Shader::Shader() {

	std::string basicVertexSource = OpenFile("shaders/basicVertex.glsl");
	std::string basicFragmentSource = OpenFile("shaders/basicFragment.glsl");

	unsigned int vertexShader = CreateShader(basicVertexSource, GL_VERTEX_SHADER);
	unsigned int fragmentShader = CreateShader(basicFragmentSource, GL_FRAGMENT_SHADER);

	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	int  success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "Error in attaching shader \n" << infoLog;
	}

	glUseProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

SG::Shader::~Shader() {
	glDeleteProgram(shaderProgram);
}

void SG::Shader::Use()
{
	glUseProgram(shaderProgram);

}
