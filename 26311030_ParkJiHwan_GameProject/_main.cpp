// include the 2d game header file
#include "glc2d.h"
#include <stdio.h>

int		nTx;					// 이미지 인덱스

VEC2	g_vcVcl(1, 0);			// Object Velocity
VEC2	g_vcPos(200, 300);		// Object Position

FLOAT	g_fSpeed  = 4;			// Object Speed
FLOAT	g_fRadius = 0;			// Radius
FLOAT	g_dRadius = 0.1F;		// Delta Radius
FLOAT	g_dDir    = 1.0F;		// Right or left rotation direction


int Render()
{
	g2_Draw2D(nTx, {}, &g_vcPos);
	return 0;
}


int main()
{
	g2_InitSdk();
	printf("그림 올리기.......................\n\n");

	//배경색을 바꾼다.
	g2_SetClearColor(0xFF336699);

	// 화면에 출력하기 위해서 함수를 연결한다.
	g2_SetRender(Render);

	// window 생성.
	g2_CreateWin(100, 100, 800, 600, "My First Game Window");


	// 그림을 프로그램에 로딩
	nTx = g2_TextureLoad("Texture/start.png");


	// 실행
	g2_Run();


	// 텍스처 해제
	g2_TextureRelease(nTx);

	// 윈도우 해제
	g2_DestroyWin();

	return 0;
}

	// 엔진을 초기화한다
	//g2_InitSdk();

	// 엔진자체
	// 엔진이 활동하는 함수포인터등을 연결
	//void	g2_SetFrameMove(int (*)());										// 게임 데이터 update 함수
	//void	g2_SetRender(int (*)());										// 게임 데이터 렌더링 함수 
	

	// window 생성.


	// 각자의 리소스를 초기화


	// RUN

	// Destroy

	
