#include "Transform.h"

namespace Engine {

	Transform::Transform()
	{
		SetScale(1.0f, 1.0f, 1.0f);
	}

	Transform::~Transform()
	{
	}

	void Transform::SetPosition(float x, float y, float z) {
		return SetPosition(Vector3(x, y, z));
	}

	void Transform::SetPosition(const Vector3 & value)
	{
		m_position = value;
	}

	void Transform::SetRotation(float x, float y, float z) {
		return SetRotation(Vector3(x, y, z));
	}

	void Transform::SetRotation(const Vector3 & value)
	{
		m_rotation = value;
	}

	void Transform::SetScale(float x, float y, float z) {
		return SetScale(Vector3(x, y, z));
	}

	void Transform::SetScale(const Vector3 & value)
	{
		m_scale = value;
	}



	Vector3& Transform::GetPosition()
	{
		return m_position;
	}
	Vector3& Transform::GetRotation()
	{
		return m_rotation;
	}
	Vector3& Transform::GetScale()
	{
		return m_scale;
	}

	Matrix4 Transform::GetMatrix() {
		Matrix4 mtxTranslate = Matrix4::CreateTranslationMatrix(m_position);
		Matrix4 mtxRotate = Matrix4::CreateRotationMatrix(m_rotation);
		Matrix4 mtxScale = Matrix4::CreateScaleMatrix(m_scale);
		Matrix4 result = (mtxTranslate * mtxRotate * mtxScale);
		return result;
	}
}