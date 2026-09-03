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
	if (g2_GetMouseEvent(1))
	{
		// Right Button
	}

	mouseX = g2_GetMouseX();
	mouseY = g2_GetMouseY();
	mouseZ = g2_GetMouseZ();

	// 윈도우 타이틀 영역에 마우스 위치 출력
	g2_SetWindowTitle("%d %d %d", mouseX, mouseY, mouseZ);

	return 0;
}

int SceneGameBegin::Render()
{
	VEC2	vcPos(mouseX, mouseY);


	g2_Draw2D(m_tx, {}, &vcPos);
	return 0;
}

