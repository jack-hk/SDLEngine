#include "Game.h"
#include "GameObject.h"
#include "Input.h"
#include "Sprite.h"
#include "Level.h"

// Included in main.cpp only.
#include "CollisionSystem.h"

// Lots of code inside Run() is for demostration purposes only. 
// The component system provided in the Game filter provides compatibility if it were to be implemented correctly.

void Run()
{
	SDL_Event _sdlEvent;

	// Object creation.
	// ----------------
	SDL_Texture* placeholder = Graphics::LoadTexture("Assets/placeholder1.png");
	SDL_Texture* placeholder2 = Graphics::LoadTexture("Assets/placeholder2.png");

	GameObject go1(Vector2D(80, 100), 80);
	go1.AddComponent(new Sprite(&go1, placeholder));
	GameObject go2(Vector2D(0, 30), 80);
	go2.AddComponent(new Sprite(&go2, placeholder2));
	GameObject go3(Vector2D(80, 230), 80);
	go3.AddComponent(new Sprite(&go3, placeholder));
	GameObject go4(Vector2D(0, 260), 80);
	go4.AddComponent(new Sprite(&go4, placeholder2));

	// Simply create the box colliders then pass GameObject values. It simulates a component, as seen in the vanilla engine (See Sprite.h).
	ColSys::BoxCollider box1 = { go1.GetPosition().x, go1.GetPosition().y, go1.GetSize(), go1.GetSize() };
	ColSys::BoxCollider box2 = { go2.GetPosition().x, go2.GetPosition().y, go2.GetSize(), go2.GetSize() };
	ColSys::CircleCollider circle1 = { go3.GetPosition().x, go3.GetPosition().y, go3.GetSize() };
	ColSys::CircleCollider circle2 = { go4.GetPosition().x, go4.GetPosition().y, go4.GetSize() };

	Level level;
	level.AddGameObject(&go1);
	level.AddGameObject(&go2);
	level.AddGameObject(&go3);
	level.AddGameObject(&go4);
	// ----------------

	//Demostration instructions
	std::cout << "INSTRUCTIONS:" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Q and E to move BoxColliders" << std::endl;
	std::cout << "A and D to move CircleColliders" << std::endl;
	std::cout << "--------------------" << std::endl;
	
	while (Game::_isRunning)
	{
		Input::Update();
		
		// The ColSys main loop function is called here.
		ColSys::CollisionSystem::Update();

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
			go3.Transform(go3.GetPosition() + (Vector2D(-1, 0)));
			std::cout << go3.GetPosition().x << std::endl;
		}
		if (Input::GetKey(SDL_SCANCODE_E))
		{
			go3.Transform(go3.GetPosition() + (Vector2D(1, 0)));
			std::cout << go3.GetPosition().x << std::endl;
		}
		box1.UpdatePosition(go1.GetPosition().x, go1.GetPosition().y);
		box2.UpdatePosition(go2.GetPosition().x, go2.GetPosition().y);
		circle1.UpdatePosition(go3.GetPosition().x, go3.GetPosition().y);
		circle2.UpdatePosition(go4.GetPosition().x, go4.GetPosition().y);

		SDL_RenderClear(Graphics::_renderer);
		Game::UpdateLevels();
		// Drawing bounding body graphics for demostration and debugging.
		Vector4D box1color = Vector4D{ 0,0,255,255 };
		Vector4D box2color = Vector4D{ 0,0,255,255 };
		Vector4D circle1color = Vector4D{ 0,0,255,255 };
		Vector4D circle2color = Vector4D{ 0,0,255,255 };

		// Checks and changes colour depending on collision status for demostration.
		if (box1.GetCollidingStatus()) box1color = Vector4D{ 255,0,0,255 };
		else box1color = Vector4D{ 0,0,255,255 };
		if (box2.GetCollidingStatus()) box2color = Vector4D{ 255,0,0,255 };
		else box2color = Vector4D{ 0,0,255,255 };
		if (circle1.GetCollidingStatus()) circle1color = Vector4D{ 255,0,0,255 };
		else circle1color = Vector4D{ 0,0,255,255 };
		if (circle2.GetCollidingStatus()) circle2color = Vector4D{ 255,0,0,255 };
		else circle2color = Vector4D{ 0,0,255,255 };
		
		// The game built-in functions draw the shapes with provided bounding bodies.
		Graphics::DrawBox(SDL_Rect{ box1.GetBody().x, box1.GetBody().y, box1.GetBody().w, box1.GetBody().h }, box1color);
		Graphics::DrawBox(SDL_Rect{ box2.GetBody().x, box2.GetBody().y, box2.GetBody().w, box2.GetBody().h }, box2color);
		Graphics::DrawCircle(Circle{ circle1.GetBody().x, circle1.GetBody().y, circle1.GetBody().r }, circle1color);
		Graphics::DrawCircle(Circle{ circle2.GetBody().x, circle2.GetBody().y, circle2.GetBody().r }, circle2color);
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