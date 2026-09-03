#pragma once
#include "glc2d.h"

class SceneGameBegin
{
public:
	int Init();
	int Update();
	int Render();
	int Destroy();

protected:
	// game texture
	int m_tx;

	int mouseX = 0;
	int mouseY = 0;
	int mouseZ = 0;

	VEC2 m_imagePos{ 100, 100 };
};

