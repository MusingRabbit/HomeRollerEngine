#include "InputController.h"

namespace Engine {

	InputController::InputController()
	{
		m_actionMap["Escape"] = SDLK_ESCAPE;
		m_pKBStateOld = nullptr;
		m_pKBState = nullptr;

		m_pKeyboard = Keyboard::Instance();
		m_pMouse = Mouse::Instance();
	}


	InputController::~InputController()
	{
		m_actionMap.clear();
		m_pMouse->clear();
		delete m_pMouse;
		delete m_pKeyboard;
		m_pKeyboard = nullptr;
		m_pMouse = nullptr;
	}

	void InputController::Update()
	{
		SDL_GetMouseState(&m_iMouseX, &m_iMouseY);
		m_pKBStateOld.reset();
		m_pKBStateOld = std::move(m_pKBState);
		m_pKBState.reset(m_pKeyboard->GetState());
	}

	Vector2 InputController::GetMousePos() {
		return m_pMouse->getPos();
	}

	Mouse* InputController::GetMouse()
	{
		return m_pMouse;
	}

	bool InputController::isButtonDown(string ActionName)
	{
		return (m_pKBState) &&
			m_pKBState->IsKeyDown(m_actionMap[ActionName]);
	}

	bool InputController::isButtonHit(string ActionName)
	{
		return (m_pKBStateOld && m_pKBState) &&
			m_pKBStateOld->IsKeyDown(m_actionMap[ActionName]) &&
			m_pKBState->IsKeyUp(m_actionMap[ActionName]);
	}

	bool InputController::SetKey(string ActionName, int Key)
	{
		if (m_actionMap[ActionName])
			return false;

		m_actionMap[ActionName] = Key;
		return true;
	}

	void InputController::ProcessSDLEvent(const SDL_Event & e)
	{
		m_pKeyboard->ProcessSDLEvent(e);
	}
}