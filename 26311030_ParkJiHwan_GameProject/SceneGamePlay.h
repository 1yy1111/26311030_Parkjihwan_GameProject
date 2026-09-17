#pragma once
#include "glc2d.h"

class SceneGamePlay
{
public:
	int Init();
	int Update();
	int Render();
	int Destroy();

public:
	void ResetGame();


protected:
	// game texture
	int m_txBg				{ -1 };
	int m_txPlayer			{ -1 };
	int m_txOpponent		{ -1 };


	// game font
	int	m_fntMessage		{ -1 };

	// game sound 
	int m_startSound		{ -1 };

	// game position
	VEC2 m_playerPos		{ 550, 595 };
	VEC2 m_opponentPos		{ 660, 595 };


	// car movespeed
	float m_playerSpeed		{ 100.f };
	float m_OpponentSpeed	{ 100.f };

	float deltaTime			{ 0.0f };


};

