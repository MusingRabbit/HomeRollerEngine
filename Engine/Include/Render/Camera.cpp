#include "Camera.h"

namespace Engine {

	Camera::Camera() :
		m_forward(0.1f, 0.1f, 1.0f),
		m_position(0.0f, 0.0f, 0.0f),
		m_Up(0.0f, 1.0f, 0.0f),
		m_yAxis(0.0f, 1.0f, 0.0f)
	{
	}

	Camera::Camera(Vector3& pos, Vector3& upVector) {
		m_Up = Vector3(upVector.x, upVector.y, upVector.z);
		m_position = Vector3(pos.x, pos.y, pos.z);
		m_forward = Vector3(0.0f, 0.0f, 1.0f);
	}


	Camera::~Camera()
	{
	}

	Matrix4 Camera::GetWorldToViewMatrix()
	{
		return Matrix4::LookAtMatrix(m_forward, m_position, m_Up);
	}

	Vector3 Camera::GetPosition()
	{
		return m_position;
	}

	void Camera::SetMovementSpeed(const float f) {
		m_movementSpeed = f;
	}

	void Camera::MouseLook(Mouse& mouse)
	{
		Vector2 deltaV = mouse.GetDelta();

		//TODO : Make this is deltaV > screen width
		if (deltaV.Length() > 100.0f) { 
			return;
		}

		m_origin = m_forward.Cross(m_Up);
		Matrix4 mtxPitch = Matrix4::CreateRotationMatrix(-deltaV.x * m_rotationSpeed, m_Up);
		Matrix4 mtxYaw = Matrix4::CreateRotationMatrix(-deltaV.y * m_rotationSpeed, m_origin);
		Matrix4 mtxRotation = mtxPitch * mtxYaw;

		m_forward = Matrix3(mtxRotation) * m_forward;
	}

	void Camera::MoveForward()
	{
		m_origin = m_forward.Cross(m_Up);
		m_position += m_forward * m_movementSpeed;
	}

	void Camera::MoveBackward()
	{
		m_origin = m_forward.Cross(m_Up);
		m_position -= m_forward * m_movementSpeed;
	}

	void Camera::MoveLeft()
	{
		m_origin = m_forward.Cross(m_Up);
		m_position += m_origin * m_movementSpeed;
	}

	void Camera::MoveRight()
	{
		m_origin = m_forward.Cross(m_Up);
		m_position -= m_origin * m_movementSpeed;
	}

	void Camera::MoveUp()
	{
	}

	void Camera::MoveDown()
	{
	}

}