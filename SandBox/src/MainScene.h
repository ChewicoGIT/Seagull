#pragma once

#include "Seagull.h"
#include <iostream>

class MainScene : public SG::Scene
{

	void Init() override {
		std::cout << "INIT";
	}

	void OnRender() override {
		SG::Graphics::DrawSquare();
	}

};

