#pragma once
#include "Math\Vector3.h"

namespace Engine {

	class Camera
	{
	public:
		Camera();
		~Camera();

	private:
		Vector3 m_position;
		Vector3 m_view;
		Vector3 m_Up;
	};

}