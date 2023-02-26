#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>

#include "Game.h"

int main(int argc, char* args[])
{
	SDL_Event _sdlEvent;

		Game::Init();
		Game::CreateWindow("Example", 800, 800, Vector4D(0, 70, 70, 255));
		Game::_isRunning = true;
		while (Game::_isRunning)
		{
			while (SDL_PollEvent(&_sdlEvent))
			{
				switch (_sdlEvent.type)
				{
				case SDL_QUIT:
					Game::_isRunning = false;
					break;
				case SDL_KEYDOWN:
					switch (_sdlEvent.key.keysym.sym)
					{
					case SDLK_ESCAPE:
						Game::_isRunning = false;
						break;
					}
					break;
				}
			}
			Game::_graphics.UpdateGraphics(Game::_renderer);
		}
		Game::DestroyWindow();
		Game::Quit();
		
	return 0;
}