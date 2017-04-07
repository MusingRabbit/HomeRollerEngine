#pragma once

#include <string>
#include <glew.h>
#include "SDL.h"
#include "Globals.h"

namespace Engine {
	class EXPORT Display {

	public :
		Display();
		Display(int width, int height);
		Display(int width, int height, const std::string& title);
		~Display();

		void Init(int width, int height, const std::string & title);
		void CreateWindow(int width, int height, const std::string & title);
		void DestroyWindow();
		void SwapBuffer();
		bool IsClosing();
		void Close();
		int GetWidth();
		int GetHeight();
		float GetAspectRatio();

	private :
		int m_iWidth;
		int m_iHeight;
		bool m_bClosing;
		std::string m_sTitle;
		SDL_Window* m_window;
		SDL_GLContext m_glContext;
	};
}