#pragma once
#include "glc2d.h"
#include <string>

class SceneGameResult
{
public:
	int Init();
	int Update();
	int Render();
	int Destroy();

private:
	// game font
	int	m_fntTitle{ -1 };
	
	std::string m_gameTitle{ "GAME OVER" };
};

