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
		this->m_startSound = g2_SoundLoad("Resource/Sound/game_start.mp3");
	}

	return 0;
}

int SceneGamePlay::Destroy()
{

	return 0;
}

void SceneGamePlay::ResetGame()
{
	m_gameTimer.Init();

	m_playerPos = VEC2(585.5f, Track::OUTER_BOTTOM_Y);
	m_opponentPos = VEC2(695.5f, Track::OUTER_BOTTOM_Y);
	m_playerTrackSection = TrackSection::BottomStraight;

	g2_SoundPlay(m_startSound);
}

void SceneGamePlay::CheckPlayerTrackSection()
{
	if (m_playerTrackSection == TrackSection::BottomStraight)
	{
		if (m_playerPos.x <= Track::LEFT_CURVE_POS_X)
		{
			m_playerPos.x = Track::LEFT_CURVE_POS_X;
			m_playerTrackSection = TrackSection::LeftCurve;
		}
	}
}

int SceneGamePlay::Update()
{
	m_gameTimer.Update();
	float deltaTime = m_gameTimer.GetDeltaTime();

	// player movement
	if (m_playerTrackSection == TrackSection::BottomStraight)
	{
		m_playerPos.x -= m_playerSpeed * deltaTime;
		CheckPlayerTrackSection();
	}





	

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

	// car
	{
		VEC2 playerDrawPos
		{
			m_playerPos.x - g2_TextureWidth(m_txPlayer) * 0.5f,
			m_playerPos.y - g2_TextureHeight(m_txPlayer) * 0.5f
		};

		VEC2 oppDrawPos
		{
			m_opponentPos.x - g2_TextureWidth(m_txOpponent) * 0.5f,
			m_opponentPos.y - g2_TextureHeight(m_txOpponent) * 0.5f
		};

		g2_Draw2D(m_txPlayer, nullptr, &playerDrawPos);
		g2_Draw2D(m_txOpponent, nullptr, &oppDrawPos);
	}

	return 0;
}
