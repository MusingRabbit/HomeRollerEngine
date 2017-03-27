#pragma once
#include <vector>
#include <iostream>
#include "SDL.h"
#include "Math\Vector2.h"

namespace Engine {

	class Mouse
	{
	public:
		Mouse(const Mouse& rhs);
		Mouse(Mouse&& rhs);
		Mouse();
		~Mouse();

		static Mouse* Instance();

		int getPosX();
		int getPosY();
		bool isLeftDown();
		bool isLeftClicked();
		bool isLeftDoubleClicked();
		Vector2 getPos();

		void ProcessSDLEvent(SDL_Event& e);
		void clear();
	private:
		static Mouse* _INSTANCE;
		void init();

		SDL_MouseButtonEvent* m_pBtnEvent;
		SDL_MouseWheelEvent* m_pWheelEvent;
		SDL_MouseMotionEvent* m_pMotionEvent;

	};

}