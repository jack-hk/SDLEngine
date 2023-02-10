#include "Graphics.h"

void Graphics::UpdateGraphics(SDL_Renderer* renderer)
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

