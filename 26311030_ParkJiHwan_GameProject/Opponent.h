#pragma once
#include "glc2d.h"
#include "Track.h"	
#include <cmath>
#include <random>

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
	int m_txOpponent			{ -1 };

	void CheckOpponentTrackSection();

	VEC2 m_position				{ 695.5f, Track::OUTER_BOTTOM_Y };
	float m_speed				{ 600.f };
	float m_curveAngle			{ 0.f };
	float m_rotationAngle		{ 0.f };

	float m_currentRadius		{ Track::OUTER_LANE_RADIUS };
	float m_lineChangeSpeed		{ 160.f };
	std::mt19937 m_randomEngine	{ std::random_device{}() };
	std::uniform_int_distribution<int> m_laneDistribution{ 1, 2 };
	float m_laneDecisionAngle	{ 0.f };
	bool m_laneDecisionDone		{ true };

	std::uniform_real_distribution<float> m_decisionOffset
	{
		Track::PI / 6.f,
		5.f * Track::PI / 6.f
	};

	TrackSection m_trackSection
	{
		TrackSection::BottomStraight
	};

	TrackLane m_lane
	{
		TrackLane::Outer
	};
};

