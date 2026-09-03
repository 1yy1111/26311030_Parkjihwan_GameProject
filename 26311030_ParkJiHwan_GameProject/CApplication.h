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

protected:
	int InitSdk();

protected:
	// windows
	POINT m_winPos{ 100, 100 };
	SIZE m_sinSize{ 800, 600 };
	
	std::string m_winName = "Game Name";

	SceneGameBegin m_sceneBegin;

	
};

