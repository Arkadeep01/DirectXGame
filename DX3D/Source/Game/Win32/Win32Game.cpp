#include <Game/Gaming.h>
#include <Windows.h>

void DX3D::Gaming::run()
{
	MSG msg{};
	while (GameisRunning)
	{
		// Game loop logic goes here
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				GameisRunning = false;
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Sleep(1); // Simulate work being done in the game loop
	};
}