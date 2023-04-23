#pragma once
#include <SDL.h>

class Input 
{
public:
	static inline const Uint8* _keyboardState;
	static inline const Uint8* _previousKeyboardState;

	static void Init();
	static void Update();
	static void Clean();

	static bool GetKey(SDL_Scancode key);
	static bool GetKeyDown(SDL_Scancode key);
	static bool GetKeyUp(SDL_Scancode key);
};