#include "Game.h"
#include "GameObject.h"
#include "Input.h"

int main(int argc, char* args[])
{
	Game::Init();
	Input::Init();
	Graphics::CreateWindow("Example", 800, 800, Vector4D(0, 70, 70, SDL_ALPHA_OPAQUE));
	Game::_isRunning = true;

	//debug
	GameObject GO(Vector2D(0, 0), 32, 32);
	RectCollider* collider = new RectCollider();
	GO.AddComponent(collider);
	//

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