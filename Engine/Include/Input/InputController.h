#pragma once
#include <algorithm>
#include <unordered_map>
#include <string>
#include <memory>
#include "SDL.h"
#include "Input\Keyboard.h"
#include "Input\Mouse.h"
using namespace std;

namespace Engine {

	class InputController
	{
	public:
		InputController();
		~InputController();

		void Update();
		bool isButtonDown(string ActionName);
		bool isButtonHit(string ActionName);
		bool SetKey(string ActionName, int Key);
		void ProcessSDLEvent(SDL_Event& e);
		Vector2 GetMousePos();
		Mouse& GetMouse();
	private:
		unique_ptr<KeyboardState> m_pKBState;
		unique_ptr<KeyboardState> m_pKBStateOld;
		unordered_map<string, Uint32> m_actionMap;
		Keyboard *m_pKeyboard;
		Mouse& m_mouse = Mouse::Instance();
		int m_iMouseX, m_iMouseY;
	};

}