#include "Graphics.h"
#include "src/core/RenderObject.h"
#include "GLAD/glad.h"
#include "src/core/ErrorHandle.h"
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>

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

void SG::Graphics::DrawObject(RenderObject* object, Dimension* dimension)
{
	basicShader->Use();
	SetDimensions(dimension->sizeX, dimension->sizeY, dimension->positionX, dimension->positionY);

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
	dimension = glm::scale(glm::mat4(1.0f), glm::vec3(sizeX, sizeY, 1.0f)) * dimension;
	dimension = glm::translate(glm::mat4(1.0f), glm::vec3(posX, posY, 0.0f)) * dimension;

	basicShader->Use();
	glUniformMatrix4fv(11, 1, GL_FALSE, glm::value_ptr(dimension));

}

void SG::Graphics::DrawInfiniteGrid(float thickness, float spacing) {

	float xScreenWidth = (float)(screenWidth * height) / (float)screenHeight;
	int linesInsideXAxis = ceil(xScreenWidth / spacing);
	int linesInsideYAxis = ceil(height / spacing);

	float firstHorizontalLine = (float)floor((xCenter - xScreenWidth / 2.0f) / spacing) * spacing;
	float pixelThickness = thickness * (float)height / (float)screenHeight;

	Dimension dim;
	for (int x = 0; x < linesInsideXAxis + 1; x++) {

		dim.sizeY = height;
		dim.sizeX = pixelThickness;
		dim.positionX = firstHorizontalLine + spacing * x;// -pixelThickness / 2.0f;
		dim.positionY = yCenter - height / 2.0f;

		DrawSquare(&dim);
	}

	float firstVerticalLine = (float)floor((yCenter - height / 2.0f) / spacing) * spacing;
	for (int y = 0; y < linesInsideYAxis + 1; y++) {

		dim.sizeY = pixelThickness;
		dim.sizeX = xScreenWidth;
		dim.positionY = firstVerticalLine + spacing * y;// -pixelThickness / 2.0f;
		dim.positionX = xCenter - xScreenWidth / 2.0f;

		DrawSquare(&dim);
	}

}

/*
float SG::Graphics::GetScreenWidth() { return screenWidth; }
float SG::Graphics::GetScreenHeight() { return screenHeight; }
int SG::Graphics::GetFrame() { return frameCount; }
float SG::Graphics::GetCameraHeight() { return height; }
float SG::Graphics::GetCameraXCenter() { return xCenter; }
float SG::Graphics::GetCameraYCenter() { return yCenter; }*/