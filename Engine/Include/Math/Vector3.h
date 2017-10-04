#pragma once
#include "MathHelper.h"
#include "Vector2.h"
#include "Quaternion.h"
#include "Globals.h"

namespace Engine {

	class EXPORT Vector3
	{
	public:
		float x;
		float y;
		float z;

		Vector3();
		Vector3(float xV, float yV, float zV);
		Vector3(const Vector2& r);
		Vector3(const Vector3& r);

		float Length();
		float Dot(const Vector3& r);
		Vector3 Normalise();
		Vector3 Cross(const Vector3& r) const;
		Vector3 Add(const Vector3& r) const;
		Vector3 Add(const float r) const;
		Vector3 Sub(const Vector3& r) const;
		Vector3 Sub(const float r) const;
		Vector3 Mul(const Vector3& r) const;
		Vector3 Mul(const float(&rhs)[3][3]) const;
		Vector3 Mul(const float r) const;
		Vector3 Div(const Vector3& r) const;
		Vector3 Div(const float r) const;
		Vector3 Rotate(float angle, const Vector3& axis) const;
		Vector3 Rotate(const float r) const;

		std::string ToString();

		const Vector3& operator=(const Vector3& rhs);

		void operator -=(const Vector3& rhs);
		void operator +=(const Vector3& rhs);
		void operator *=(const Vector3& rhs);
		void operator /=(const Vector3& rhs);
		void operator -=(const float rhs);

		Vector3 operator *(const Vector3& rhs) const;
		Vector3 operator *(const float(&rhs)[3][3]) const;
		Vector3 operator *(const float rhs) const;
		Vector3 operator -(const float rhs) const;
		Vector3 operator -(const Vector3& rhs) const;
		Vector3 operator +(const Vector3& rhs) const;
		Vector3 operator /(const Vector3& rhs) const;
	};























}