// include the 2d game header file
#include "glc2d.h"
#include <stdio.h>
#include "CApplication.h"

CApplication g_app;


int main()
{
	g_app.Init();

	// ½ÇÇà
	g2_Run();


	g_app.Destroy();

	return 0;
}