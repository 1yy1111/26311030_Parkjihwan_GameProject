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
	int m_tx		{ -1 };
	int m_txBg		{ -1 };
	int m_txCar		{ -1 };
	int m_txTitle	{ -1 };

	// game font
	int	m_fntMessage{ -1 };

	int m_gameScore	{ -1 };
	
	int mouseX = 0;
	int mouseY = 0;
	int mouseZ = 0;

	VEC2 m_imagePos	{ 670, 600 };
	VEC2 m_imagePoss{ 550, 600 };
	VEC2 m_titlePos{ 500, 450 };


};

