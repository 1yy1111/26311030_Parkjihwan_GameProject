#include "CApplication.h"
#include "glc2d.h"

CApplication g_app;

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
    m_scenePlay.Init();
    m_sceneResult.Init();

    return 0;
}

int CApplication::Update()
{
    if (Scene::Begin == m_currentScene)
    {
        m_sceneBegin.Update();
    }
    else if (Scene::Play == m_currentScene)
    {
        m_scenePlay.Update();
    }
    else if (Scene::Result == m_currentScene)
    {
        m_sceneResult.Update();
    }

    return 0;
}

int CApplication::Render()
{
    // 공통 배경, 차
    m_scenePlay.Render();

    
    if (Scene::Begin == m_currentScene)
    {
        m_sceneBegin.Render();
    }
    else if (Scene::Result == m_currentScene)
    {
        m_sceneResult.Render();
    }

    return 0;
}

int CApplication::Destroy()
{
    m_sceneResult.Destroy();
    m_scenePlay.Destroy();
    m_sceneBegin.Destroy();

    // 윈도우 해제
    g2_DestroyWin();

    return 0;
}

SIZE CApplication::GetWinSize()
{
    return m_winSize;
}

void CApplication::ChangeScene(Scene scene)
{
    if (m_currentScene == scene)
    {
        return;
    }

    // Begin -> Play, Result -> Play일땐 새 게임 시작
    if (Scene::Play == scene)
    {
        m_scenePlay.ResetGame();
    }

    m_currentScene = scene;
}

int CApplication::InitSdk()
{
    // SDK 초기화
    g2_InitSdk();

    g2_SetFrameMove(AppUpdate);
    g2_SetRender(AppRender);

    // window 생성.
    g2_CreateWin(m_winPos.x, m_winPos.y, m_winSize.cx, m_winSize.cy, m_winName.c_str());

    //배경색을 바꾼다.
    g2_SetClearColor(0xFF336699);

    return 0;
}
