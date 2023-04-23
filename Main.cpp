#include "Game.h"
#include "GameObject.h"
#include "Input.h"
#include "Sprite.h"
#include "Level.h"

//
#include "Collision.h"
//

void Run()
{
	SDL_Event _sdlEvent;

	//
	SDL_Texture* placeholder = Graphics::LoadTexture("Assets/placeholder1.png");

	GameObject go1(Vector2D(50, 100), 80);
	go1.AddComponent(new Sprite(&go1, placeholder));

	GameObject go2(Vector2D(10, 10), 80);
	go2.AddComponent(new Sprite(&go2, placeholder));

	ColSys::BoxCollider box1 = { go1.GetPosition().x, go1.GetPosition().y, 1, 1 };
	ColSys::BoxCollider box2 = { go2.GetPosition().x, go2.GetPosition().y, 1, 1 };

	Level level;
	level.AddGameObject(&go1);
	level.AddGameObject(&go2);
	//

	while (Game::_isRunning)
	{
		Input::Update();
		//
		ColSys::CollisionSystem::UpdateSystem();
		//
		while (SDL_PollEvent(&_sdlEvent))
		{
			switch (_sdlEvent.type)
			{
			case SDL_QUIT:
				Game::_isRunning = false;
				break;
			}
		}

		//
		if (Input::GetKey(SDL_SCANCODE_A))
		{
			go1.Transform(go1.GetPosition() + (Vector2D(-1, 0)));
			std::cout << go1.GetPosition().x << std::endl;
		}
		if (Input::GetKey(SDL_SCANCODE_D))
		{
			go1.Transform(go1.GetPosition() + (Vector2D(1, 0)));
			std::cout << go1.GetPosition().x << std::endl;
		}
		if (Input::GetKey(SDL_SCANCODE_Q))
		{
			go2.Transform(go2.GetPosition() + (Vector2D(-1, 0)));
			std::cout << go2.GetPosition().x << std::endl;
		}
		if (Input::GetKey(SDL_SCANCODE_E))
		{
			go2.Transform(go2.GetPosition() + (Vector2D(1, 0)));
			std::cout << go2.GetPosition().x << std::endl;
		}
		box1.UpdatePosition(go1.GetPosition().x, go1.GetPosition().y);
		box2.UpdatePosition(go2.GetPosition().x, go2.GetPosition().y);
		//

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