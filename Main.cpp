#include "Game.h"
#include "GameObject.h"
#include "Input.h"
#include "Sprite.h"
#include "Level.h"

// Included in main.cpp only.
#include "CollisionSystem.h"

void Run()
{
	SDL_Event _sdlEvent;
	ColSys::CollisionSystem colSystem;

	// Object creation.
	// ----------------
	SDL_Texture* placeholder = Graphics::LoadTexture("Assets/placeholder1.png");

	GameObject go1(Vector2D(50, 100), 80);
	go1.AddComponent(new Sprite(&go1, placeholder));

	GameObject go2(Vector2D(10, 30), 80);
	go2.AddComponent(new Sprite(&go2, placeholder));
	
	// Simply create the box colliders then pass GameObject values. It simulates a component, as seen in the vanilla engine (See Sprite.h).
	colSystem.CreateBox("Box1", go1.GetPosition().x, go1.GetPosition().y, go1.GetSize(), go2.GetSize());
	colSystem.CreateBox("Box2", go1.GetPosition().x, go1.GetPosition().y, go1.GetSize(), go2.GetSize());

	Level level;
	level.AddGameObject(&go1);
	level.AddGameObject(&go2);
	// ----------------

	while (Game::_isRunning)
	{
		Input::Update();
		
		// The ColSys main loop function is called here.
		//ColSys::CollisionSystem::Update();
		
		while (SDL_PollEvent(&_sdlEvent))
		{
			switch (_sdlEvent.type)
			{
			case SDL_QUIT:
				Game::_isRunning = false;
				break;
			}
		}

		// Input movement, for the demostration.
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
		colSystem.GetBox("Box1");
		colSystem.GetBox("Box2");

		// Graphics updates.
		SDL_RenderClear(Graphics::_renderer);
		Game::UpdateLevels();
		// Drawing bounding body graphics for demostration and debugging.
		//Graphics::DrawBox(SDL_Rect{ box1.GetBody().x, box1.GetBody().y, box1.GetBody().h, box1.GetBody().w }, Vector4D(255, 0, 0, 255));
		//Graphics::DrawBox(SDL_Rect{ box2.GetBody().x, box2.GetBody().y, box2.GetBody().h, box2.GetBody().w }, Vector4D(0, 0, 255, 255));
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