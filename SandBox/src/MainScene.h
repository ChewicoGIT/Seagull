#pragma once

#include "Seagull.h"
#include <iostream>

class MainScene : public SG::Scene
{

	void Init() override {
		SG::Graphics::SetColor(0.2f, 0.4f, 0.8f, 1.0f);
		SG::Graphics::SetCamera(10, 0, 0);
	}
	
	bool lastMousePres = false;
	float xOffset;
	float yOffset;

	void OnRender() override {
		float positionX = (float)SG::Graphics::GetFrame() / 100.0f;

		SG::Graphics::SetColor(1, 1, 1, 0.2f);
		SG::Graphics::DrawInfiniteGrid(1, 0.2f);
		SG::Graphics::SetColor(1, 1, 1, 0.3f);
		SG::Graphics::DrawInfiniteGrid(1, 1.0f);
		SG::Graphics::SetColor(1, 1, 1, 0.5f);
		SG::Graphics::DrawInfiniteGrid(1, 5.0f);

		SG::Graphics::SetColor(0.2f, 0.4f, 0.8f, 1.0f);
		SG::Dimension dim{
			1.0f, 1.0f, positionX - 2, -5.0f
		};

		float xPosition, yPosition;
		if (SG::Interaction::UserCameraPosition(&xPosition, &yPosition)) {
			SG::Graphics::SetCamera(10, xPosition, yPosition);
		}


		//std::cout << x << " - " << y << "\n";

		SG::Graphics::DrawTriangle(&dim);
	}

};

