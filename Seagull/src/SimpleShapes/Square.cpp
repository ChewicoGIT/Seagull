#include "Square.h"
#include "GLAD/glad.h"
#include "GLFW/glfw3.h"

signed char squareVertexData[]{
	0, 0, 0,
	 1, 0, 0,
	0,  1, 0,
	1,  1, 0
};

char indices[]{
	0, 2, 1, 1, 2, 3
};


SG::Square::Square() {
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(squareVertexData), squareVertexData, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_BYTE, GL_FALSE,3 * sizeof(signed char), (void*)0);
	glEnableVertexAttribArray(0); 


}