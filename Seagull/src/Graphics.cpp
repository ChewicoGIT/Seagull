#include "Graphics.h"
#include "src/core/RenderObject.h"
#include "GLAD/glad.h"
#include "src/core/ErrorHandle.h"

SG::Shader* SG::Graphics::basicShader;
SG::Square* SG::Graphics::square;

void SG::Graphics::Initialize()
{
	
	basicShader = new Shader();
	square = new Square();

}

void SG::Graphics::DrawObject(RenderObject* object)
{
	basicShader->Use();

	glBindVertexArray(object->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);

}
