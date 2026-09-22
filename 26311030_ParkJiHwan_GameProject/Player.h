#pragma once
#include "glc2d.h"
#include "Track.h"


class Player
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
    int m_txPlayer{ -1 };

    void CheckPlayerTrackSection();

    VEC2 m_position{ 585.5f, Track::OUTER_BOTTOM_Y };
    float m_speed{ 500.f };

    TrackSection m_trackSection
    {
        TrackSection::BottomStraight
    };

};

