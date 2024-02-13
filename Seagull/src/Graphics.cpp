#include "Graphics.h"

SG::Shader* SG::Graphics::basicShader;
bool SG::Graphics::initialized = false;

void SG::Graphics::Initialize()
{
	if (initialized)
		return;
	initialized = true;

	basicShader = new Shader();

}
