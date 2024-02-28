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
		SG::Dimension dim;

		dim.rotation += positionX;

		float xPosition, yPosition;
		if (SG::Interaction::UserCameraPosition(&xPosition, &yPosition)) {
			//SG::Graphics::SetCamera(10, xPosition, yPosition);
		}

		SG::Graphics::SetColor(0.2f, 0.4f, 0.8f, 1.0f);
		if (SG::Interaction::MouseTriggerArea(&dim))
			SG::Graphics::SetColor(0.6f, 0.8f, 0.9f, 1.0f);
		SG::Graphics::DrawSquare(&dim);
	}

};

