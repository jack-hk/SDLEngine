#pragma once
#include <vector>

#include "Graphics.h"
#include "Input.h"

//Deals with gameloop and common game functions
class Level;
class Game
{
public:
	static inline Graphics _graphics;
	static inline bool _isRunning;
	static inline bool _isDebugMode = true;
	static inline std::vector<Level*> _levels;

	static void Init();
	static void Quit();

	static void UpdateLevels();
};