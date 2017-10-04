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

		static Mouse& Instance();

		int GetX();
		int GetY();
		bool isLeftDown();
		bool isLeftClicked();
		bool isLeftDoubleClicked();
		Vector2 GetPosition();
		Vector2 GetDelta();
		void ProcessSDLEvent(SDL_Event& e);
		float GetSensitivity();
		void SetSensitivity(const float v);

		Mouse& operator=(const Mouse& rhs);

	private:
		void init();

		SDL_MouseButtonEvent m_pBtnEvent;
		SDL_MouseWheelEvent m_pWheelEvent;
		SDL_MouseMotionEvent m_pMotionEvent;

		float m_sensitivity = 0.1f;
	};

}