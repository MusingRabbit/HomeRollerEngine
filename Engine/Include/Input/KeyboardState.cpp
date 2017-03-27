#include "KeyboardState.h"

namespace Engine
{
	//Constructor
	KeyboardState::KeyboardState()
	{
	}

	//Copy Constructor
	KeyboardState::KeyboardState(const KeyboardState& other)
	{
		m_keyMap = other.m_keyMap;
	}

	//Move Constructor
	KeyboardState::KeyboardState(KeyboardState&& other)
	{
		m_keyMap = other.m_keyMap;
		other.m_keyMap.clear();
	}


	KeyboardState::KeyboardState(vector<int> Keys)
	{
		SetPressedKeys(Keys);
	}

	//Deconstructor
	KeyboardState::~KeyboardState(void)
	{
		m_keyMap.clear();
	}

	KeyboardState& KeyboardState::operator = (KeyboardState &&rVal)
	{
		if (this != &rVal)
		{
			m_keyMap = rVal.m_keyMap;
		}

		return *this;
	}

	KeyboardState& KeyboardState::operator = (const KeyboardState &rVal)
	{
		if (this != &rVal)
		{
			m_keyMap = rVal.m_keyMap;
		}

		return *this;
	}

	bool KeyboardState::IsKeyDown(int key)
	{
		return  m_keyMap[key];
	}

	bool KeyboardState::IsKeyUp(int key)
	{
		return !m_keyMap[key];
	}

	void KeyboardState::SetPressedKeys(vector<int> Keys)
	{
		int iKeys = Keys.size();

		m_keyMap.clear();

		for (int i = 0; i < iKeys; i++) {
			m_keyMap[Keys[i]] = true;
		}
	}
}