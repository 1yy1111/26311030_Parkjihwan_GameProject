#include "GameTimer.h"

GameTimer::GameTimer()
{
    Reset();
}

void GameTimer::Reset()
{
    auto now = Clock::now();

    m_baseTime = now;
    m_prevTime = now;
    m_deltaTime = 0.0f;
    m_totalTime = 0.0f;

}

void GameTimer::Tick()
{

}

float GameTimer::GetDeltaTime() const
{
    return 0.0f;
}

float GameTimer::GetTotalTime() const
{
    return 0.0f;
}
