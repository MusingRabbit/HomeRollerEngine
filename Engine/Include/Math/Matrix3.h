#pragma once
#include "Matrix4.h"
#include "Globals.h"

namespace Engine {

	class EXPORT Matrix3
	{
	public:
		static const int iCount = 3;
		float m[iCount][iCount];

		static Matrix3 GetIdentity() {
			Matrix3 result;
			for (int x = 0; x < iCount; x++) {
				for (int y = 0; y < iCount; y++) {
					result.m[x][y] = (x == y) ? 1.0f : 0.0f;
				}
			}
			return result;
		}

		Matrix3();
		Matrix3(const float(&rhs)[3][3]);
		Matrix3(Matrix4& value);

		Matrix3 Mul(const float(&rhs)[3][3]);
		Matrix3 Mul(const Matrix3& rhs);
		Vector3 Mul(const Vector3& rhs);

		Matrix3 operator* (const Matrix3& rhs);
		Matrix3 operator*= (const Matrix3& rhs);
		Vector3 operator* (const Vector3& rhs);
	};
}