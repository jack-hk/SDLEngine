#include "Game.h"

void Game::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}
	std::cout << "SDL" << ": Sucessfully initialised" << std::endl;
}

void Game::Run() 
{
	SDL_Event _sdlEvent;

	//debug
	SDL_Texture* tex = Graphics::LoadTexture("Assets/placeholder1.png");
	GameObject GO(Vector2D(0, 0), 128, 128);
	RectCollider* collider = new RectCollider();
	GO.AddComponent(collider);
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

		if (!_isRunning) break;

		if (Input::GetKeyDown(SDL_SCANCODE_W)) std::cout << "W was pressed" << std::endl;
		if (Input::GetKeyUp(SDL_SCANCODE_S)) std::cout << "S was released" << std::endl;

		if (Input::GetKey(SDL_SCANCODE_A)) std::cout << "A is held" << std::endl;
		if (Input::GetKey(SDL_SCANCODE_D)) std::cout << "D is held" << std::endl;

		//Graphics::UpdateGraphics();
		SDL_RenderClear(Graphics::_renderer);
		Graphics::DrawImage(tex, GO.srcRect, GO.dstRect);
		SDL_RenderPresent(Graphics::_renderer);
	}
}

void Game::Quit()
{
	SDL_Quit();
	std::cout << "SDL" << ": Cleaned up SDL subsystems" << std::endl;
}