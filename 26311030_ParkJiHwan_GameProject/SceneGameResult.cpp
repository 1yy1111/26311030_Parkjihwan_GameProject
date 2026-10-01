#include "SceneGameResult.h"

int SceneGameResult::Init()
{
	this->m_fntTitle = g2_FontCreate("NeoµÕ±Ù¸ð", 90);

	return 0;
}

int SceneGameResult::Destroy()
{
	return 0;
}

int SceneGameResult::Update()
{
	return 0;
}

int SceneGameResult::Render()
{
	RECT rcTitle{ 435, 225, 900, 325 };

	g2_FontDrawText(m_fntTitle, rcTitle, 0XFF8B352B, "s", m_gameTitle.c_str());
	return 0;
}
