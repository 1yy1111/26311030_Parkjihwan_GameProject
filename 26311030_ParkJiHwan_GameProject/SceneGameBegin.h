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
	int m_txBg		{ -1 };
	int m_txTitle	{ -1 };
	int m_txPlayer{ -1 };
	int m_txOpponent{ -1 };


	// game font
	int	m_fntMessage{ -1 };

	

	// game position
	VEC2 m_playerPos{ 550, 595 };
	VEC2 m_opponentPos{ 660, 595 };
	VEC2 m_titlePos{ 360, 215 };


};

