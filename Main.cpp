#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>

#include "Game.h"

int main(int argc, char* args[])
{
	Game _game{};
	SDL_Event sdlEvent;
	std::vector<Game> _gameInstances = { _game };

	for (auto gameInts : _gameInstances)
	{
		gameInts.Init();
		gameInts.CreateWindow("Example", 800, 800, Vector4D(0, 0, 0, 255));
		gameInts._isRunning = true;
		while (SDL_PollEvent(&sdlEvent))
		{
			switch (sdlEvent.type)
			{
			case SDL_QUIT:
				gameInts._isRunning = false;
				break;
			case SDL_KEYDOWN:
				switch (sdlEvent.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					gameInts._isRunning = false;
					break;
				}
				break;
			default:
				break;
			}
		}
		getchar();
		
		gameInts.DestroyWindow();
		gameInts.Quit();
	}
	return 0;
}