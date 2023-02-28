#include "Game.h"

int main(int argc, char* args[])
{
	SDL_Event _sdlEvent;

		Game::Init();
		Graphics::CreateWindow("Example", 800, 800, Vector4D(0, 70, 70, SDL_ALPHA_OPAQUE));
		Game::_isRunning = true;
		while (Game::_isRunning) //put in game.h
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
			Graphics::UpdateGraphics(Graphics::_renderer);
		}
		Graphics::DestroyWindow();
		Game::Quit();
		
	return 0;
}