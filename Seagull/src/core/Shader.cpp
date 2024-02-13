#include "Shader.h"
#include <iostream>
#include <fstream>
#include <string>

std::string OpenFile(const char* filePath) {

	std::ifstream shaderFile;
	shaderFile.open(filePath);

	if (!shaderFile.is_open()) {
		std::cout << filePath << " could not be open \n";
		return std::string("No path");
	}

	std::string returnContent;

	while (shaderFile.good()) {
		shaderFile >> returnContent;
	}

	return returnContent;	
}

SG::Shader::Shader() {

	std::cout << OpenFile("shaders/basicFragment.glsl") << "\n";

}

SG::Shader::~Shader() {

}