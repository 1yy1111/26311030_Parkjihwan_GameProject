#pragma once
#include "glc2d.h"

class SceneGameBegin
{
public:
	int Init();
	int Update();
	int Render();
	int Destroy();

protected:
	// game texture
	int m_txTitle		{ -1 };


	// game font
	int	m_fntMessage	{ -1 };


	// text blink
	static constexpr long long BLINK_INTERVAL{ 500 };
	bool m_isTextVisible{ true };
	

	// game position
	VEC2 m_titlePos		{ 360, 215 };


};

