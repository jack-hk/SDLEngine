#pragma once
#include <vector>

#include "Graphics.h"

class Level;
class Game // Deals with gameloop and common game functions.
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