#include "Game.h"
#include "GameObject.h"
#include "Input.h"
#include "Sprite.h"
#include "Level.h"

void Run()
{
	SDL_Event _sdlEvent;

	// adding component example
	SDL_Texture* placeholder = Graphics::LoadTexture("Assets/placeholder1.png");
	GameObject go1(Vector2D(50, 50), 20);
	//go1.AddComponent(new Sprite(&go1, placeholder));
	go1.AddComponent(new BoxCollider(&go1));

	GameObject go2(Vector2D(100, 50), 20);
	//go2.AddComponent(new Sprite(&go2, placeholder));
	go2.AddComponent(new BoxCollider(&go2));
	Level level;
	level.AddGameObject(&go1);
	level.AddGameObject(&go2);
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

		if (!Game::_isRunning)
		{
			std::cout << "Game is shutting down..." << std::endl;
			break;
		}

		//debug movement
		if (Input::GetKey(SDL_SCANCODE_A))
		{
			go2.Transform(go2.GetPosition() + (Vector2D(-1, 0)));
			std::cout << go2.GetPosition().x << std::endl;
		}
		if (Input::GetKey(SDL_SCANCODE_D))
		{
			go2.Transform(go2.GetPosition() + (Vector2D(1, 0)));
			std::cout << go2.GetPosition().x << std::endl;
		}
		//

		SDL_RenderClear(Graphics::_renderer);

		//debug drawing. put inside Graphics.h
		Graphics::DrawBox(go1.GetComponent<BoxCollider>()->GetBodyBounds(), Vector4D(255, 0, 0, SDL_ALPHA_OPAQUE));
		Graphics::DrawBox(go2.GetComponent<BoxCollider>()->GetBodyBounds(), Vector4D(0, 0, 255, SDL_ALPHA_OPAQUE));
		//

		Game::UpdateLevels();
		SDL_RenderPresent(Graphics::_renderer);
	}
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

/*
* Should I split "UpdateLevels" into multiple updates? such as graphics, audio, physics, etc.
* 
*/

/* Dan's feedback
* - use std::bind
* - use std::functional
* - see examples
* 
* the collision library must make up its own definition of 'component' called Collider
* should not inherit from Component
* destroy the classes Shape, VectorMath and SDLCommon
*/

/* Pelumi's feedback
*  - Remove SDLCommon for the engine module. Shape translations and maths goes inside Collision.h
*  - Completely remove Shape.h, GameObject.h and Component.h dependencies
*/


/* Notes
* 
* https://en.cppreference.com/w/cpp/utility/functional/bind
* 
* not performant to follow OOP's polymorphism in the case of components. it's better to use Data Orientated Design methods.
* 
* -For every 'new' make sure you 'delete'.
* 
* -look into using constructors instead of 'init' functions
* 
* 
* 
* apporaches to decoupling in context of current design:
* 
* 1. RenderableComponent class
* i create a class that any object which requires drawing functions, must inherit from. this adds another layer to inheritance and follows OOP
* 
* 2. IsRendered property
* skips the extra class and instead puts a Draw() function inside GameObject and a 'isRendered' property inside each component (that needs it). then components can tell GameObject class whether Draw is ignored or not inside Update
*/

