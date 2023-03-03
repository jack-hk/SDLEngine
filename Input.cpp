#include "Input.h"

void Input::Init()
{
	_keyboardState = SDL_GetKeyboardState(NULL);
	_previousKeyboardState = (Uint8*)malloc(SDL_NUM_SCANCODES);
}

void Input::Update()
{
	SDL_memcpy((void*)_previousKeyboardState, _keyboardState, SDL_NUM_SCANCODES);
}

void Input::Clean()
{
	free((void*)_previousKeyboardState);
}

bool Input::GetKey(SDL_Scancode key)
{
	return _keyboardState[key];
}

bool Input::GetKeyDown(SDL_Scancode key)
{
	return _keyboardState[key] && !(_previousKeyboardState[key]);
}

bool Input::GetKeyUp(SDL_Scancode key)
{
	return !(_keyboardState[key]) && _previousKeyboardState[key];
}