#pragma once
#include <chrono>

class GameTimer
{
public:
	GameTimer();

	void Reset();
	void Tick();

	float GetDeltaTime() const;
	float GetTotalTime() const;


private:
	using Clock = std::chrono::high_resolution_clock;
	using TimePoint = std::chrono::time_point<Clock>;

private:
	TimePoint m_baseTime;
	TimePoint m_prevTime;
	float m_deltaTime;
	float m_totalTime;

};

