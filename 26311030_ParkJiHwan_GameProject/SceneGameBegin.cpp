#include "SceneGameBegin.h"
#include "glc2d.h"

int SceneGameBegin::Init()
{ 
	m_tx = g2_TextureLoad("resource/start.png");
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
		m_imagePos = VEC2(mouseX-250, mouseY-20);
	}


	// 윈도우 타이틀 영역에 마우스 위치 출력
	g2_SetWindowTitle("%d %d %d", mouseX, mouseY, mouseZ);

	return 0;
}

int SceneGameBegin::Render()
{

	g2_Draw2D(m_tx, {}, &m_imagePos);
	return 0;
}

