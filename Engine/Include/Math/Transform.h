#pragma once
#include "Vector3.h"
#include "Matrix4.h"
#include "Globals.h"

namespace Engine {

	class EXPORT Transform
	{
	public:
		Transform();
		~Transform();

		void SetPosition(float x, float y, float z);
		void SetPosition(const Vector3& value);
		void SetRotation(float x, float y, float z);
		void SetRotation(const Vector3 & value);
		void SetScale(float x, float y, float z);
		void SetScale(const Vector3 & value);
		Vector3 & GetPosition();
		Vector3 & GetRotation();
		Vector3 & GetScale();
		Matrix4 GetMatrix();

	private:
		Vector3 m_position;
		Vector3 m_rotation;
		Vector3 m_scale;
	};
}