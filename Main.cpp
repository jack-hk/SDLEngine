#include "Game.h"
#include "GameObject.h"
#include "Input.h"

//QA
//contents of Run inside main.cpp? yes.

int main(int argc, char* args[])
{
	Game::Init();
	Input::Init();
	Graphics::CreateWindow("Example", 800, 800, Vector4D(0, 70, 70, SDL_ALPHA_OPAQUE));
	Game::_isRunning = true;

	Game::Run();
	Input::Clean();
	Graphics::DestroyWindow();
	Game::Quit();

	return 0;
}

/* Notes
* 
* -For every 'new' make sure you 'delete'.
*/