#include "Game.h"
#include "GameObject.h"
#include "Input.h"
#include "Sprite.h"
#include "Level.h"

void Run()
{
	SDL_Event _sdlEvent;
	
	//

	//
	
	while (Game::_isRunning)
	{
		Input::Update();
		while (SDL_PollEvent(&_sdlEvent))
		{
			switch (_sdlEvent.type)
			{
			case SDL_QUIT:
				Game::_isRunning = false;
				break;
			}
		}

		SDL_RenderClear(Graphics::_renderer);
		Game::UpdateLevels();
		SDL_RenderPresent(Graphics::_renderer);
	}
	std::cout << "Game is shutting down..." << std::endl;
}


int main(int argc, char* args[])
{
	Game::Init();
	Input::Init();
	Graphics::CreateWindow("Example", 800, 800, Vector4D(0, 70, 70, SDL_ALPHA_OPAQUE));
	Game::_isRunning = true;

	Run();

	Graphics::DestroyWindow();
	Input::Clean();
	Game::Quit();

	return 0;
}