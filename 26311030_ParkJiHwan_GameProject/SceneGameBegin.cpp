#include "SceneGameBegin.h"
#include "CApplication.h"
#include "glc2d.h"
#include <windows.h>

int SceneGameBegin::Init()
{
	// texture
	this->m_txTitle = g2_TextureLoad("Resource/Texture/Title.png");

	// font
	this->m_fntMessage = g2_FontCreate("Neo둥근모", 32);

	return 0;
}

int SceneGameBegin::Destroy()
{
	return 0;
}

int SceneGameBegin::Update()
{
	// start guide
	long long currentTime = g2_TimeGetTime();

	if (0 == (currentTime / BLINK_INTERVAL) % 2)
	{
		m_isTextVisible = false;
	}
	else
	{
		m_isTextVisible = true;
	}

	// scene change
	const KEYCODE* pKey = g2_GetKeyboard();
	if (pKey[VK_RETURN])
	{
		g_app.ChangeScene(Scene::Play);
	}

	return 0;
}

int SceneGameBegin::Render()
{
	// title
	{
		g2_Draw2D(m_txTitle, nullptr, &m_titlePos);
	}

	// start guide
	if (m_isTextVisible)
	{
		RECT rc{ 475, 430, 975, 490 };
		g2_FontDrawText(m_fntMessage, rc, 0xFF17243A, "Enter 키를 눌러 시작");
	}

	return 0;
}

