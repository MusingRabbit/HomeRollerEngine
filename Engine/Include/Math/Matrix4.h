#pragma once
#include "MathHelper.h"
#include "Vector3.h"
#include <Globals.h>

namespace Engine {

	class EXPORT Matrix4
	{
	public:
		static const uint iCount = 4;
		float m[iCount][iCount];

		Matrix4();

		Matrix4(const float(&value)[4][4]);

		void InitIdentity();

		void SetTranslation(Vector3& value);
		void SetTranslation(float x, float y, float z);

		void SetData(const float(&value)[4][4]);

		Matrix4 Mul(const Matrix4& rhs);
		Matrix4 Mul(const float(&rhs)[4][4]);

		static Matrix4 CreatePerspectiveMatrix(float fov, float aspect, float zNear, float zFar);
		static Matrix4 CreateRotationMatrix(const Vector3& value);
		static Matrix4 CreateRotationMatrix(const float amt, Vector3& dir);
		static Matrix4 LookAtMatrix(Vector3& fwd, Vector3& pos, Vector3& up);
		static Matrix4 CreateRotationMatrix(float x, float y, float z);
		static Matrix4 CreateScaleMatrix(const Vector3& value);
		static Matrix4 CreateScaleMatrix(float x, float y, float z);
		static Matrix4 CreateIdentityMatrix();
		static Matrix4 CreateTranslationMatrix(const Vector3& value);
		static Matrix4 CreateTranslationMatrix(float x, float y, float z);
		Matrix4 operator* (const Matrix4& rhs);
		Matrix4 operator* (const float(&rhs)[4][4]);
		Matrix4 operator *= (const Matrix4& rhs);
		Matrix4 operator *= (const float(&rhs)[4][4]);
	};
}