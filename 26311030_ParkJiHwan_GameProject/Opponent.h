#pragma once
#include "glc2d.h"
#include "Track.h"	

class Opponent
{
public:
	int Init();
	int Destroy();
	int Render();
	int Update(float deltaTime);

public:
	void Reset();
	VEC2 GetPosition() const;

private:
	int m_txOpponent{ -1 };

	void CheckOpponentTrackSection();

	VEC2 m_position{ 695.5f, Track::OUTER_BOTTOM_Y };
	float m_speed{ 500.f };

	TrackSection m_trackSection
	{
		TrackSection::BottomStraight
	};
};

