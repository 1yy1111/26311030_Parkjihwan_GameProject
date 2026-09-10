#include "SceneGameBegin.h"
#include "CApplication.h"
#include "glc2d.h"
#include <windows.h>

int SceneGameBegin::Init()
{ 
	this->m_txBg = g2_TextureLoad("resource/Resource/background.png", 0);
	this->m_tx = g2_TextureLoad("resource/Resource/sport_red.png");
	this->m_txCar = g2_TextureLoad("resource/Resource/sport_yellow.png");
	
	this->m_txTitle = g2_TextureLoad("resource/Resource/start.png");

	//this->m_fntMessage = g2_FontCreate("Bahnschrift", 32);
	return 0;
}

int SceneGameBegin::Destroy()
{
	return 0;
}

int SceneGameBegin::Update()
{
	mouseX = g2_GetMouseX();
	mouseY = g2_GetMouseY();
	mouseZ = g2_GetMouseZ();


	if (g2_GetMouseEvent(0))
	{
		m_imagePos = VEC2(mouseX, mouseY);
		m_imagePoss = VEC2(mouseX-120, mouseY);
	}


	// 윈도우 타이틀 영역에 마우스 위치 출력
	g2_SetWindowTitle("%d %d %d", mouseX, mouseY, mouseZ);

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
		//g2_Draw2D(m_txTitle, nullptr, &m_titlePos);
	}

	// 메뉴
	{



		g2_Draw2D(m_tx, nullptr, &m_imagePos);		
		g2_Draw2D(m_txCar, nullptr, &m_imagePoss);
	}
	

	// 폰트
	{
	/*	RECT rc{ 400, 400, 840, 600 };
		g2_FontDrawText(m_fntMessage, rc, 0xFFFF00FF, "enter를 눌러 시작");*/
	}
	return 0;
}

