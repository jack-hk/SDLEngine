#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>

#include "Game.h"

int main(int argc, char* args[])
{
	Game _game{};
	SDL_Event _sdlEvent;
	std::vector<Game> _gameInstances = { _game };

	for (auto gameInts : _gameInstances)
	{
		gameInts.Init();
		gameInts.CreateWindow("Example", 800, 800, Vector4D(0, 70, 70, 255));
		gameInts._isRunning = true;
		while (gameInts._isRunning)
		{
			while (SDL_PollEvent(&_sdlEvent))
			{
				switch (_sdlEvent.type)
				{
				case SDL_QUIT:
					gameInts._isRunning = false;
					break;
				case SDL_KEYDOWN:
					switch (_sdlEvent.key.keysym.sym)
					{
					case SDLK_ESCAPE:
						gameInts._isRunning = false;
						break;
					}
					break;
				}
			}
			gameInts._graphics.UpdateGraphics(gameInts.GetRenderer());
		}

		gameInts.DestroyWindow();
		gameInts.Quit();
	}
	return 0;
}