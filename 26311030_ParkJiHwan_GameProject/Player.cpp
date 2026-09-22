#include "Player.h"

int Player::Init()
{
	// texture loading
	m_txPlayer = g2_TextureLoad("Resource/Texture/sport_yellow.png");

	return 0;
}

int Player::Destroy()
{
	return 0;
}

void Player::Reset()
{
	m_position = VEC2(585.5f, Track::OUTER_BOTTOM_Y);
	m_speed = 500.f;
	m_trackSection = TrackSection::BottomStraight;
}

int Player::Update(float deltaTime)
{
	if (m_trackSection == TrackSection::BottomStraight)
	{
		m_position.x -= m_speed * deltaTime;
		CheckPlayerTrackSection();
	}

	return 0;
}

int Player::Render()
{
	VEC2 playerDrawPos
	{
		m_position.x - g2_TextureWidth(m_txPlayer) * 0.5f,
		m_position.y - g2_TextureHeight(m_txPlayer) * 0.5f
	};

	g2_Draw2D(m_txPlayer, nullptr, &playerDrawPos);
	return 0;
}

VEC2 Player::GetPosition() const
{
	return m_position;
}

void Player::CheckPlayerTrackSection()
{
	if (TrackSection::BottomStraight == m_trackSection)
	{
		if (m_position.x <= Track::LEFT_CURVE_POS_X)
		{
			m_position.x = Track::LEFT_CURVE_POS_X;
			m_trackSection = TrackSection::LeftCurve;
		}
	}
}
