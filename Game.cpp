#include "Game.h"

void Game::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}
	std::cout << "SDL" << ": Sucessfully initialised" << std::endl;
}

void Game::Quit()
{
	SDL_Quit();
	std::cout << "SDL" << ": Cleaned up SDL subsystems" << std::endl;
}