#pragma once

#include "Graphics.h"

//Deals with gameloop and common game functions.
class Game
{
public:
	static inline Graphics _graphics;
	static inline bool _isRunning;

	static void Init();
	static void Quit();
};

