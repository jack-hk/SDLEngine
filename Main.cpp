#include "Game.h"
#include "GameObject.h"
#include "Input.h"
#include "Sprite.h"
#include "Level.h"

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

void Game::Run()
{
	SDL_Event _sdlEvent;

	// adding component example
	SDL_Texture* placeholder = Graphics::LoadTexture("Assets/placeholder1.png");
	GameObject go1(Vector2D(0, 0));
	go1.AddComponent(new Sprite(&go1, placeholder));
	Level level;
	level.AddGameObject(&go1);
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
		Game::UpdateLevels();
		SDL_RenderPresent(Graphics::_renderer);
	}
}
