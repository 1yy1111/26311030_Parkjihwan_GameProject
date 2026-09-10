#pragma once
#include <windows.h>
#include <string>
#include "SceneGameBegin.h"

class CApplication
{
public:
	int Init();
	int Update();
	int Render();
	int Destroy();

public:
	SIZE GetWinSize();

protected:
	int InitSdk();

protected:
	// windows
	POINT m_winPos{ 0, 0 };
	SIZE m_winSize{ 1280, 720 };
	
	std::string m_winName = "Game Name";

	SceneGameBegin m_sceneBegin;

	
};

// 전역 접근
extern CApplication g_app;
