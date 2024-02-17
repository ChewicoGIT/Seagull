#include "Graphics.h"
#include "src/core/RenderObject.h"
#include "GLAD/glad.h"
#include "src/core/ErrorHandle.h"
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

SG::Shader* SG::Graphics::basicShader;
SG::Square* SG::Graphics::square;

int SG::Graphics::screenWidth;
int SG::Graphics::screenHeight;
float SG::Graphics::height;
float SG::Graphics::xCenter;
float SG::Graphics::yCenter;
int SG::Graphics::frameCount;

void SG::Graphics::Initialize()
{
	
	basicShader = new Shader();
	square = new Square();

}

void SG::Graphics::DrawObject(RenderObject* object)
{
	basicShader->Use();

	glBindVertexArray(object->VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object->IBO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	

}

void SG::Graphics::SetColor(float r, float g, float b, float a)
{
	basicShader->Use();
	glUniform4f(10, r, g, b, a);

}

void SG::Graphics::SetCamera(float height, float xCenter, float yCenter)
{

	glm::mat4 identity(1.0f);
	glUniformMatrix4fv(11, 1, GL_FALSE, glm::value_ptr(identity));

	SG::Graphics::height = height;
	SG::Graphics::xCenter = xCenter;
	SG::Graphics::yCenter = yCenter;

}

void SG::Graphics::PreRender() {

	//Set camera matrix
	basicShader->Use();
	float width = (float)(screenWidth * height) / (float)screenHeight;
	glm::mat4 CamMat = glm::ortho(
		xCenter - width / 2.0f,
		xCenter + width / 2.0f,
		yCenter - height / 2.0f,
		yCenter + height / 2.0f,
		-1.0f, 1.0f);
	glUniformMatrix4fv(12, 1, GL_FALSE, glm::value_ptr(CamMat));

}

void SG::Graphics::SetDimensions(float sizeX, float sizeY, float posX, float posY) {
	glm::mat4 dimension(1.0f);
	dimension = glm::scale(dimension, glm::vec3(sizeX, sizeY, 1.0f));
	dimension = glm::translate(dimension, glm::vec3(posX, posY, 1.0f));

	basicShader->Use();
	glUniformMatrix4fv(11, 1, GL_FALSE, glm::value_ptr(dimension));

}