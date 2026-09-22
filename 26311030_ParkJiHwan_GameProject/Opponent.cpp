#include "Opponent.h"

int Opponent::Init()
{
	// texture loading
	m_txOpponent = g2_TextureLoad("Resource/Texture/sport_red.png");
	return 0;
}

int Opponent::Destroy()
{
	return 0;
}

int Opponent::Update(float deltaTime)
{
	if (m_trackSection == TrackSection::BottomStraight)
	{
		m_position.x += m_speed * deltaTime;
		CheckOpponentTrackSection();
	}
	return 0;
}

int Opponent::Render()
{
	VEC2 opponentDrawPos
	{
		m_position.x - g2_TextureWidth(m_txOpponent) * 0.5f,
		m_position.y - g2_TextureHeight(m_txOpponent) * 0.5f
	};
	g2_Draw2D(m_txOpponent, nullptr, &opponentDrawPos);
	return 0;
}

VEC2 Opponent::GetPosition() const
{
	return m_position;
}

void Opponent::Reset()
{
	m_position = VEC2(695.5f, Track::OUTER_BOTTOM_Y);
	m_speed = 500.f;
	m_trackSection = TrackSection::BottomStraight;
}

void Opponent::CheckOpponentTrackSection()
{
	if (m_trackSection == TrackSection::BottomStraight)
	{
		if (m_position.x >= Track::RIGHT_CURVE_POS_X)
		{
			m_position.x = Track::RIGHT_CURVE_POS_X;
			m_trackSection = TrackSection::RightCurve;
		}
	}
}