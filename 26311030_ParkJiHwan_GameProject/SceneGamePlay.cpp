#include "SceneGamePlay.h"
#include "CApplication.h"
#include "glc2d.h"
#include <windows.h>


int SceneGamePlay::Init()
{
	// texture
	this->m_txBg = g2_TextureLoad("Resource/Texture/background.png", 0);



	// sound
	this->m_startSound = g2_SoundLoad("Resource/Sound/game_start.mp3");


	m_player.Init();
	m_opponent.Init();

	return 0;
}

int SceneGamePlay::Destroy()
{
	m_player.Destroy();
	m_opponent.Destroy();

	return 0;
}

void SceneGamePlay::ResetGame()
{
	m_gameTimer.Init();
	m_player.Reset();
	m_opponent.Reset();
	
	g2_SoundPlay(m_startSound);
}

int SceneGamePlay::Update()
{
	m_gameTimer.Update();
	float deltaTime = m_gameTimer.GetDeltaTime();
	m_player.Update(deltaTime);
	m_opponent.Update(deltaTime);



	return 0;
}

int SceneGamePlay::Render()
{
	// background
	{
		auto winSize = g_app.GetWinSize();
		auto bgTexW = (float)g2_TextureWidth(m_txBg);
		auto bgTexH = (float)g2_TextureHeight(m_txBg);
		VEC2 bgScale{ winSize.cx / bgTexW, winSize.cy / bgTexH };
		g2_Draw2D(m_txBg, nullptr, nullptr, &bgScale);
	}

	m_player.Render();
	m_opponent.Render();
	return 0;
}
