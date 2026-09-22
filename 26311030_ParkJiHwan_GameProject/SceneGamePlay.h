#pragma once
#include "glc2d.h"
#include "GameTimer.h"
#include "Track.h"
#include "Player.h"
#include "Opponent.h"

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

	// game font
	int	m_fntMessage		{ -1 };

	// game sound 
	int m_startSound		{ -1 };


	GameTimer m_gameTimer;
	Player m_player;
	Opponent m_opponent;
};

