#include "SceneGameBegin.h"
#include "CApplication.h"
#include "glc2d.h"
#include <windows.h>

int SceneGameBegin::Init()
{ 
	this->m_txBg = g2_TextureLoad("Resource/Texture/background.png", 0);
	this->m_txOpponent = g2_TextureLoad("Resource/Texture/sport_red.png");
	this->m_txPlayer = g2_TextureLoad("Resource/Texture/sport_yellow.png");
	
	this->m_txTitle = g2_TextureLoad("Resource/Texture/Title.png");

	this->m_fntMessage = g2_FontCreate("Neo둥근모", 32);
	return 0;
}

int SceneGameBegin::Destroy()
{
	return 0;
}

int SceneGameBegin::Update()
{


	return 0;
}

int SceneGameBegin::Render()
{
	// 배경
	{
		auto winSize = g_app.GetWinSize();
		auto bgTexW = (float)g2_TextureWidth(m_txBg);
		auto bgTexH = (float)g2_TextureHeight(m_txBg);
		VEC2 bgScale{ winSize.cx / bgTexW, winSize.cy / bgTexH };
		g2_Draw2D(m_txBg, nullptr, nullptr, &bgScale);
	}

	// title
	{
		g2_Draw2D(m_txTitle, nullptr, &m_titlePos);
	}

	// 메뉴
	{
		
		g2_Draw2D(m_txPlayer, nullptr, &m_playerPos);
		g2_Draw2D(m_txOpponent, nullptr, &m_opponentPos);
	}
	

	// 폰트
	{
		RECT rc{ 475, 430, 975, 490 };
		g2_FontDrawText(m_fntMessage, rc, 0xFF17243A, "Enter 키를 눌러 시작");
	}
	return 0;
}

