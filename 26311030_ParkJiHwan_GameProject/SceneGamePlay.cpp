#include "SceneGamePlay.h"
#include "CApplication.h"
#include "glc2d.h"
#include <windows.h>


int SceneGamePlay::Init()
{
	// texture
	{
		this->m_txBg = g2_TextureLoad("Resource/Texture/background.png", 0);
		this->m_txOpponent = g2_TextureLoad("Resource/Texture/sport_red.png");
		this->m_txPlayer = g2_TextureLoad("Resource/Texture/sport_yellow.png");
	}

	// sound
	{
		this->m_startSound = g2_SoundLoad("Resoure/Sound/game_start.mp3");
	}

	return 0;
}

int SceneGamePlay::Destroy()
{

	return 0;
}

void SceneGamePlay::ResetGame()
{
	m_playerPos = VEC2(550, 595);
	m_opponentPos = VEC2(660, 595);

}

int SceneGamePlay::Update()
{
	long long currentTime = g2_TimeGetTime();
	


	m_playerPos.x += m_playerSpeed * deltaTime;
	


	g2_SoundPlay(m_startSound);

	return 0;
}

int SceneGamePlay::Render()
{
	// backGround
	{
		auto winSize = g_app.GetWinSize();
		auto bgTexW = (float)g2_TextureWidth(m_txBg);
		auto bgTexH = (float)g2_TextureHeight(m_txBg);
		VEC2 bgScale{ winSize.cx / bgTexW, winSize.cy / bgTexH };
		g2_Draw2D(m_txBg, nullptr, nullptr, &bgScale);
	}

	// car
	{
		g2_Draw2D(m_txPlayer, nullptr, &m_playerPos);
		g2_Draw2D(m_txOpponent, nullptr, &m_opponentPos);
	}

	return 0;
}
