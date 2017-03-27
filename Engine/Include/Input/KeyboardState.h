#ifndef KEYBOARDSTATE_H
#define KEYBOARDSTATE_H

#include <vector>
#include <algorithm>
#include <string.h>
#include <unordered_map>

using namespace std;

namespace Engine {
	class KeyboardState
	{
	public:

		//Copy Constructor
		KeyboardState(const KeyboardState& rhs);
		//Move Constructor
		KeyboardState(KeyboardState&& other);
		//
		KeyboardState(vector<int> Keys);
		//Default Constructor
		KeyboardState();
		//Deconstructor
		~KeyboardState();

		bool IsKeyDown(int Key);
		bool IsKeyUp(int Key);
		void SetPressedKeys(vector<int> Keys);


		KeyboardState& operator = (const KeyboardState &rVal);
		KeyboardState& operator = (KeyboardState &&rVal);

	private:
		unordered_map<int, bool> m_keyMap;
	};

}

#endif