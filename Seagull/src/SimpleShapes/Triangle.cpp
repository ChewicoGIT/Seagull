#include "Triangle.h"
#include "GLAD/glad.h"
#include "GLFW/glfw3.h"


SG::Triangle::Triangle() {

	float triangleVertexData[]{
		-0.5f, 0, 0,
		0, 1.0f, 0,
		0.5f,  0, 0
	};

	unsigned int indices[]{
		0, 1, 2
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertexData), triangleVertexData, GL_STATIC_DRAW);

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

}

