#pragma once
#include "glc2d.h"
#include "GameTimer.h"


namespace Track
{
	// curve position
	constexpr float LEFT_CURVE_POS_X{ 334.0f };
	constexpr float RIGHT_CURVE_POS_X{ 946.0f };
	constexpr float CURVE_POS_Y{ 358.0f };

	// lane radii
	constexpr float INNER_LANE_RADIUS{ 204.0f };
	constexpr float OUTER_LANE_RADIUS{ 252.0f };

	// straight lane positions
	constexpr float INNER_TOP_Y
	{
		CURVE_POS_Y - INNER_LANE_RADIUS
	};
	constexpr float INNER_BOTTOM_Y{
		CURVE_POS_Y + INNER_LANE_RADIUS
	};

	constexpr float OUTER_TOP_Y
	{
		CURVE_POS_Y - OUTER_LANE_RADIUS
	};
	constexpr float OUTER_BOTTOM_Y
	{
		CURVE_POS_Y + OUTER_LANE_RADIUS
	};
}

enum class TrackSection
{
    BottomStraight,
    LeftCurve,
    TopStraight,
    RightCurve
};

class SceneGamePlay
{
public:
	int Init();
	int Update();
	int Render();
	int Destroy();

public:
	void ResetGame();
	void CheckPlayerTrackSection();

protected:
	// game texture
	int m_txBg				{ -1 };
	int m_txPlayer			{ -1 };
	int m_txOpponent		{ -1 };


	// game font
	int	m_fntMessage		{ -1 };

	// game sound 
	int m_startSound		{ -1 };

	// game position
	VEC2 m_playerPos		{ 585.5f, Track::OUTER_BOTTOM_Y };
	VEC2 m_opponentPos		{ 695.5f, Track::OUTER_BOTTOM_Y };

	// game timer
	GameTimer m_gameTimer;

	// car movespeed
	float m_playerSpeed		{ 500.f };
	float m_opponentSpeed	{ 100.f };

	// track section
	TrackSection m_playerTrackSection{ TrackSection::BottomStraight };
};

