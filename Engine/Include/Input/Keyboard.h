#pragma once
#include <vector>
#include <iostream>
#include "SDL.h"
#include "KeyboardState.h"


using namespace std;

namespace Engine {

	class Keyboard
	{
	public:
		//Copy Constructor
		Keyboard(const Keyboard& rhs);
		//Move Constructor
		Keyboard(Keyboard&& other);
		//Default Constructor
		Keyboard();
		//Deconstructor
		~Keyboard();

		vector<int> KeyList;

		static Keyboard* Instance();
		void ProcessSDLEvent(const SDL_Event& e);

		KeyboardState* GetState();

	private:
		vector<int> GetPressedKeys();
		static Engine::Keyboard* _INSTANCE;
	};

}