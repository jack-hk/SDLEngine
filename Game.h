#pragma once
#include <vector>

#include "Graphics.h"
#include "Level.h"
#include "Input.h"

//Deals with gameloop and common game functions
class Game
{
public:
	static inline Graphics _graphics;
	static inline bool _isRunning;
	static inline std::vector<Level*> _levels;

	static void Init();
	static void Run();
	static void Quit();
};

