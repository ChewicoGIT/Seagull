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
		SG::Graphics::SetColor(1, 1, 1, 0.1f);
		SG::Graphics::DrawInfiniteGrid(1, 0.5f / 4.0f);
		SG::Graphics::SetColor(1, 1, 1, 0.2f);
		SG::Graphics::DrawInfiniteGrid(1, 0.5f);
		SG::Graphics::SetColor(1, 1, 1, 0.3f);
		SG::Graphics::DrawInfiniteGrid(1, 2.0f);
		SG::Graphics::SetColor(1, 1, 1, 0.5f);
		SG::Graphics::DrawInfiniteGrid(1, 4.0f);

		SG::Graphics::SetColor(0.2f, 0.4f, 0.8f, 1.0f);
		SG::Dimension dim{
			1.0f, 1.0f, positionX - 2, -5.0f
		};

		float x, y;

		SG::Input::GetCursorPositionOnSpace(&x, &y);
		x -= SG::Graphics::GetCameraXCenter();
		y -= SG::Graphics::GetCameraYCenter();

		SG::Graphics::SetCamera(10, -x, -y);

		//std::cout << x << " - " << y << "\n";

		SG::Graphics::DrawSquare(&dim);
	}

};

