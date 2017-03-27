#pragma once

#include <glew.h>
#include <iostream>
#include <string>
#include "Core\Game.h"
#include "Core\Display.h"
#include "Globals.h"
#include "SDL.h"

namespace Engine {
	class EXPORT Launcher
	{
	public:
		Launcher();
		~Launcher();

		void Initialise(std::string Title, int Width, int Height);

		void Start();
		void Run();
		void Stop();

	private:
		Game m_game;
		Display m_display;

		bool m_bRun;
		void Clean();
	};
}
