#pragma once

#include "Seagull.h"
#include <iostream>

class MainScene : public SG::Scene
{

	void Init() override {
		SG::Graphics::SetColor(0.2f, 0.4f, 0.8f, 1.0f);
		SG::Graphics::SetCamera(10, 0, 0);
	}

	void OnRender() override {
		float positionX = (float)SG::Graphics::GetFrame() / 100.0f;
		SG::Graphics::SetDimensions(1, 1, positionX - 7, 0);
		SG::Graphics::DrawSquare();
	}

};

