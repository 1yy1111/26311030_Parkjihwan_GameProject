#include "CApplication.h"
#include "SceneGameBegin.h"
#include "glc2d.h"
#include <stdio.h>

extern CApplication g_app;

int AppUpdate()
{
    return g_app.Update();
}

int AppRender()
{
    return g_app.Render();
}


int CApplication::Init()
{
    InitSdk();

    m_sceneBegin.Init();
    return 0;
}

int CApplication::Update()
{
    printf("Update");

    m_sceneBegin.Update();
    return 0;
}

int CApplication::Render()
{
    printf("Render");

    m_sceneBegin.Render();

    return 0;
}

int CApplication::Destroy()
{
    m_sceneBegin.Destroy();

    // 윈도우 해제
    g2_DestroyWin();

    return 0;
}

int CApplication::InitSdk()
{
    // SDK 초기화
    g2_InitSdk();
    printf("Start  ...\n\n");

    g2_SetFrameMove(AppUpdate);
    g2_SetRender(AppRender);

    // window 생성.
    g2_CreateWin(m_winPos.x, m_winPos.y, m_sinSize.cx, m_sinSize.cy, m_winName.c_str());

    //배경색을 바꾼다.
    g2_SetClearColor(0xFF336699);

    return 0;
}
