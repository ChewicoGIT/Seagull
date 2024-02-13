#include "Square.h"
#include "GLAD/glad.h"
#include "GLFW/glfw3.h"

signed char squareVertexData[2 * 4]{
	-1, -1,
	 1, -1,
	-1,  1,
	 1,  1
};

SG::Square::Square() {
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(squareVertexData), &squareVertexData, GL_STATIC_DRAW);


}