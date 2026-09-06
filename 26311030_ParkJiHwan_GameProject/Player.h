#pragma once
#include "glc2d.h"

class Player
{
public:
	int Init();
	int Update();
	int Render();
	int Destroy();

protected:
	VEC2 m_pos;		// 플레이어 위치
	float m_speed;	// 플레이어 스피드
};

