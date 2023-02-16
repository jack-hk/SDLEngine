#include "Game.h"

void Game::Init()
{
	//Initialise SDL and all subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}
	std::cout << this << ": Sucessfully initialised" << std::endl;
}

void Game::CreateWindow(const char *window_title, int window_width, int window_height, Vector4D window_color)
{
	_window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN);
	if (_window == nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == nullptr)
	{
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
	}

	SDL_SetRenderDrawColor(_renderer, window_color.h, window_color.i, window_color.j, window_color.k);
	std::cout << this << ": Successfully created window and renderer" << std::endl;
}

void Game::DestroyWindow()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	std::cout << this << ": Destroyed window and renderer" << std::endl;
}

void Game::Quit()
{
	SDL_Quit();
	std::cout << this << ": Cleaned up SDL subsystems" << std::endl;
}

SDL_Window* Game::GetWindow()
{
	return _window;
}

SDL_Renderer* Game::GetRenderer()
{
	return _renderer;
}
