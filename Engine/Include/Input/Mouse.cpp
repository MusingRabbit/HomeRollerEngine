#include "Mouse.h"

namespace Engine 
{
	Mouse::Mouse(const Mouse & rhs)
	{
	}

	Mouse::Mouse(Mouse && rhs)
	{
	}

	Mouse::Mouse()
	{
		init();
	}

	Mouse::~Mouse()
	{
	}

	void Mouse::init() {

	}

	float Mouse::GetSensitivity()
	{
		return m_sensitivity;
	}

	void Mouse::SetSensitivity(const float v)
	{
		m_sensitivity = v;
	}

	Mouse & Mouse::operator=(const Mouse & rhs)
	{
		if (this != &rhs){
			*this = rhs;
		}
		return *this;
	}

	void Mouse::ProcessSDLEvent(SDL_Event& e)
	{
		m_pBtnEvent = e.button;
		m_pWheelEvent = e.wheel;
		m_pMotionEvent = e.motion;
	}

	Mouse& Mouse::Instance() {
		static Mouse INSTANCE;
		return INSTANCE;
	}

	int Mouse::GetX()
	{
		return m_pMotionEvent.x;
	}

	int Mouse::GetY()
	{
		return m_pMotionEvent.y;
	}

	Vector2 Mouse::GetPosition()
	{
		return Vector2((float)GetX(), (float)GetY());
	}

	bool Mouse::isLeftDown()
	{
		return m_pBtnEvent.button == 1;
	}

	bool Mouse::isLeftClicked()
	{
		return m_pBtnEvent.clicks == 1 && m_pBtnEvent.button == 1;
	}
	bool Mouse::isLeftDoubleClicked()
	{
		return m_pBtnEvent.clicks == 2 && m_pBtnEvent.button == 1;;
	}

	Vector2 Mouse::GetDelta()
	{
		return Vector2(m_pMotionEvent.xrel, m_pMotionEvent.yrel);
	}
}