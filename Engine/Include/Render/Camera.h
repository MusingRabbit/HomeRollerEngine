#pragma once
#include "Input\Mouse.h"
#include "Math\Vector3.h"
#include "Math\Matrix4.h"
#include "Math\Matrix3.h"

#include <iostream>

namespace Engine {

	class Camera
	{
	public:
		Camera();
		Camera(Vector3 & pos, Vector3 & upVector);
		~Camera();

		Matrix4 GetWorldToViewMatrix();
		Vector3 GetPosition();
		
		void MouseLook(Mouse& mouse);
		void MoveForward();
		void MoveBackward();
		void MoveLeft();
		void MoveRight();
		void MoveUp();
		void MoveDown();

		void SetMovementSpeed(const float f);

	private:
		Vector3 m_position;
		Vector3 m_forward;
		Vector3 m_Up;
		Vector3 m_origin;

		Vector3 m_yAxis;

		float m_movementSpeed = 0.1f;
		float m_rotationSpeed = 0.1f;
	};

}