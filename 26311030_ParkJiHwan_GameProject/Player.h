#pragma once
#include "glc2d.h"
#include "Track.h"
#include <cmath>

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
    TrackSection GetTrackSection() const;
    void IncreaseSpeed(float amount);

private:
    int m_txPlayer          { -1 };

    void CheckPlayerTrackSection();

    VEC2 m_position         { 585.5f, Track::OUTER_BOTTOM_Y };
    float m_speed           { 600.0f };
    float m_curveAngle      { 0.0f };
    float m_rotationAngle   { 0.0f };

	float m_currentRadius   { Track::OUTER_LANE_RADIUS };
    bool m_wasMouseDown     { false };

    TrackSection m_trackSection
    {
        TrackSection::BottomStraight
    };

    TrackLane m_lane
    {
        TrackLane::Outer 
    };
};

