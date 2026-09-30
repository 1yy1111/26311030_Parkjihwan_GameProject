#pragma once
#include "glc2d.h"
#include <windows.h>
#include "GameTimer.h"
#include "Track.h"
#include "Player.h"
#include "Opponent.h"


class SceneGamePlay
{
public:
	int Init();
	int Update();
	int RenderWorld();
	int Render();
	int Destroy();

public:
	void ResetGame();

protected:
	bool CheckCollision(VEC2 playerPos, VEC2 opponentPos);
	bool CheckFinishLine(VEC2 previousPos, VEC2 currentPos);

	// game texture
	int m_txBg				{ -1 };

	// game font
	int	m_fntMessage		{ -1 };

	// game sound 
	int m_startSound		{ -1 };

	int m_gameScore			{ 0 };	


	GameTimer m_gameTimer;
	Player m_player;
	Opponent m_opponent;
};

